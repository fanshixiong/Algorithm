# Codeforces Round #624 (Div. 3) F. Moving Points

![img](https://img2018.cnblogs.com/i-beta/1405118/202002/1405118-20200227202100039-524460766.png)

 

 

 **题意：**给定$n$个点的初始坐标$x$和速度$v$（保证$n$个点的初始坐标互不相同）， $d(i,j)$是第$i$个和第$j$个点之间任意某个时刻的最小距离，求出$n$个点中任意一对点的$d(i,j)$的总和。

**题解：**可以理解，两个点中初始坐标较小的点的速度更大时，总有一个时刻后面的点会追上前面的点，$d(i,j) =0。$

　　　否则，即后面的点的速度 <= 前面的点的速度时，两点之间的距离只会越来越大，$d(i,j) = abs(x_i - x_j)$　（初始距离）。

可以用直线来辅助理解：$x = x_i + v*t，$横轴为t，纵轴为x，若两直线交点t值大于等于0，则$d(i,j) = 0$。否则交点t值为负 或者两直线平行时，$d(i,j)=初始距离$。

![img](https://img2018.cnblogs.com/i-beta/1405118/202002/1405118-20200227204141287-23106398.png)

 

 　　　所以，立即会想到对点按初始坐标排序，遍历每个点，计算出前面点中 速度小于等于 当前点的 所有点与当前点的初始距离总和。n可达$2*10^5$，需要找$O(n log(n))$的算法。

　　若当前点下标为i，前面所有速度不大于当前点的点下标为$j_1，j_2，...，$相当于求$（x[i]-x[j_1]）+（x[i]-x[j_2]）+（x[i]-x[j_3]）... = num * x[i] - sum(x[j])。$即需要使用一个数据结构来维护前面速度较小点的数量 和 初始距离x的总和。

　　最佳选择就是树状数组，按初始坐标递增的顺序依次添加点的信息，一个树状数组记录小于等于当前速度的点的个数，另一个记录这些点的初始距离总和。

　　由于速度范围比较大，需要进行离散化处理，即把n个速度离散成n_个下标，树状数组正好对应这个下标。

**详细见代码和注释如下：

```cpp
#include<cstdio>
#include<utility>      //pair
#include<algorithm>    //sort
#include<vector>    　 //lower_bound, unique
using namespace std;
 
const int maxn = 2e5 + 2;
pair<int, int>a[maxn];    //存所有点的(初始坐标，速度)
int v[maxn], n;            //所有点的速度，点的个数
 
long long s1[maxn], s2[maxn];    //两个树状数组
void add(int i, int x) {
    while (i <= n) {
        s1[i]++;        //s1存个数，每次增加1
        s2[i] += x;        //s2存初始坐标x的总和，每次增加x
        i += i & (-i);
    }
}

long long getSum(long long s[], int i) {
    long long res(0);
    while (i > 0) {
        res += s[i];
        i -= i & (-i);
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)scanf("%d", &a[i].first);
    for (int i = 1; i <= n; i++) {
        scanf("%d", v + i);
         a[i].second = v[i];
     }
     sort(a + 1, a + n + 1);
     sort(v + 1, v + n + 1);
     int *vend = unique(v + 1, v + n + 1);    //速度离散化为 v[1]到v[vend-1 - v]
     long long ans = 0LL;
     for (int i = 1; i <= n; i++) {    //按x递增顺序向树状数组中添加点的信息，初始两个树状数组都为空
         //得到x第i小的点 的v值 在v数组中对应的下标pos
        int pos = lower_bound(v + 1, vend, a[i].second) - v;
        //得到速度小于等于a[i].second的点的个数和x总和
        long long sum1 = getSum(s1, pos), sum2 = getSum(s2, pos);
        ans += sum1 * a[i].first - sum2;    //num * x[i] - num个x[j]的和。(对所有的x[j]<x[i])
        add(pos, a[i].first);
    }
    printf("%lld", ans);
    return 0;
}   
```

