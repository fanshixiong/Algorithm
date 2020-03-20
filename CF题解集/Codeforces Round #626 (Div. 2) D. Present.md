# Codeforces Round #626 (Div. 2) D. [Present](https://codeforces.com/contest/1323/problem/D)

### 题意：

求n个数中两两和的异或。

### 思路：

逐位考虑，第k位只需考虑$0~k-1$位，可通过$\&(2k+1-1)$得到一组新数。

将新数排序，当两数和在$[2k,2k+1)$和$[2k+1+2k，2k+2)$之间时该位为1，又因为两数的最大和为$2*(2k+1-1)=2k+2-2$，

即当两数和在$[2k,2k+1)$和$[2k+1+2k，2k+2-2]$之间时该位为1。

对于每个数，找到和

　　　　* 大于等于$2k$

　　　　* 小于$2k+1$

　　　　* 大于等于$2k+1+2k$

的三个临界点（因为两数之和一定小于等于$2k+2-2$，所以第四个临界点可以忽略），

位于它们间的数与该数的和在第k位即为1，统计1的个数，该位异或偶数次后为0，异或奇数次后为1。



```cpp
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

int n, ans;
int a[maxn], b[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int k = 0; k < 25; k++){
        for (int j = 0; j < n; j++){
            b[j] = a[j] & ((1 << (k + 1)) - 1);
        }
        sort(b, b + n);

        int d = 1 << k;
        int cnt = 0, x = 0, y = 0, z = 0;
        for (int j = n - 1; j >= 0; j--){
            while(x<n && b[x] + b[j]<d) x++;
            while(y<n && b[y] + b[j]<2*d) y++;
            while(z<n && b[z] + b[j]<3*d) z++;

            cnt += max(0, min(j, y) - x); //
            cnt += max(0, j - z);        //不懂
        }

        if(cnt & 1)
            ans |= (1 << k);
    }
    cout << ans << endl;
    return 0;
}
```

 