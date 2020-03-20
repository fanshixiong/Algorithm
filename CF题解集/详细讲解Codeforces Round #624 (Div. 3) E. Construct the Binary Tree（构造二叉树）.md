# Codeforces Round #624 (Div. 3) E. Construct the Binary Tree（构造二叉树）

![img](https://img2018.cnblogs.com/i-beta/1405118/202002/1405118-20200227154902914-1654491116.png)

**题意：**给定节点数n和所有节点的深度总和d，问能否构造出这样的二叉树。能，则输出“YES”，并且输出$n-1$个节点的父节点（节点1为根节点）。

**题解：**n个节点构成的二叉树中，完全（满）二叉树的深度总和最小，单链树（左/右偏数）的深度总和最大。若d在这个范围内，则一定能构造出来；否则一定构造不出来。

* 初始构造一颗单链树，依次把底部的节点放入上面的层，直到满足深度总和为d

* 若当前深度总和sum > d，则先拿掉底端节点。

　　　* 拿掉后，若sum依然比d大，就直接把底端节点放入有空位的最上层；

　　　*  拿掉后$sum <= d，dif = d - sum。$

　　　* 若$dif >=$ 此时有空位的最上层深度，则深度为dif的层一定有空位，把底端节点放入该层，即可完成构造。

* 否则，依然把底端节点放入有空位的最上层，修改后的sum依旧比d大，继续循环即可。

　　　　3.退出循环后就完成了构造，获得了所求的树。

具体存储结构、表示方式和算法过程见代码（和注释）：

```cpp
#include<bits/stdc++.h>
using namespace std;

int layer[5005], num[5005];    //layer[i]先存第i+1个点所在层的深度，num[i]是深度为i的层里的节点数

int main() {
    int t, n, d;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &d);
        memset(num, 0, sizeof num);
        int sum = n * (n - 1) / 2, dep = 0, minn = 0;
        num[0] = 1;        //0深度层只有一个根节点
        for (int i = 2; i <= n; i++) {
            //i&(i - 1)的结果为把i二进制下最后一个1置0。i&(i - 1) == 0时，i为2的整数次幂
            if ((i&(i - 1)) == 0)dep++;        //第i+1层的第一个节点为2^i
            minn += dep;                    //minn记录满二叉树时的深度总和

            layer[i - 1] = i - 1;    //单链树时，和为sum，layer[i]是第i+1个点所在层的深度
            num[i - 1] = 1;            //num[i]记录深度为i的层的节点总数
        }
        if (d<minn || d>sum) {
            puts("NO");
            continue;
        }
        puts("YES");
        dep = 1;    //当前有空位的最上层的深度
        for (int i = n - 1; i > 0 && sum > d; i--) {
            sum -= i;        //拿掉底端顶点
            num[i]--;
            if (sum > d) {            //拿掉之后，sum仍然比d大时；直接放最上面
                layer[i] = dep;        //第i+1个点现在的深度为dep
                sum += dep;

                if (++num[dep] == (1 << dep))dep++;    //若最上面的层满了，修改为下一层
            }
            else {                    //拿掉之后，sum<=d时
                int dif = d - sum;        //看差值对应的层是否有空位
                if (dif >= dep) {            //有空位，则直接放到深度等于差值的那一层，构造成功
                    layer[i] = dif;
                    sum += dif;    //写出来更好理解
                    num[dif]++;    //该层节点数++
                    break;
                }
                else {                        //无空位，只能放最上面dep层
                    layer[i] = dep;
                    sum += dep;                //此时sum仍然 > d
                    if (++num[dep] == (1 << dep))dep++;    //若最上面的层满了，修改为下一层
                }
            }
        }
        //构造成功。layer[i]是原来单链树中深度为i的点(第i+1个点) 现在的深度，num[i]是第i层的节点总数
        //现只用num中的信息求解；layer中的信息只是辅助理解，现在用来存最终答案(即第i个节点的父节点编号)
        int id(2), fid(1);    //当前节点编号，上一层首个节点的编号
        for (int i = 1; num[i]; i++) {    // while(深度为i的层节点数不为0)
            for (int j = 0; j < num[i]; j++) {
                //深度为i的层的第j个节点，在完全二叉树中的编号为(1<<i)+j，上一层首个节点编号为1<<(i - 1)
                //layer[id++] = fid + ((1 << i) + j) / 2 - (1 << (i - 1)); 直接算这个式子会溢出
                layer[id++] = fid + j / 2;    //简化后得出，也可以直接理解推出来
            }
            fid += num[i - 1];
        }
        for (int i = 2; i < n; i++)
            printf("%d ", layer[i]);
        printf("%d\n", layer[n]);
    }
    return 0;
}
```

