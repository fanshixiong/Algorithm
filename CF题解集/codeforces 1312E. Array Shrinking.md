# codeforces 1312E. Array Shrinking

### 题意：
相同的两个$x$可以合并成$x+1$，给一个序列，问最后数组中最少能剩下多少个数。

### 思路:

数据500，很明显的区间dp数据。
考虑之前区间$sum[1] [j]$表示$i，j$合并以后能得到一个$k$，如果$k=0$，表示不能合并到一起。
先预处理$sum[i][j]$的元素个数为$j-i+1$，$sum[i][i]=a[i]$。
然后就是常规区间dp了，枚举区间长度，区间起点和区间终点。
只有当左区间和右区间的长度为1且左右区间各自合并出来的数字相等时才可以合并，即$sum[i][k]==dp[k+1][j]\&\&sum[i][k]>0$。

最后更新dp。

代码:

```cpp
#include<bits/stdc++.h>
using namespace std;
const int maxn = 510;
int a[maxn], dp[maxn], sum[maxn][maxn];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i][i] = a[i];
    }
    for (int len = 1; len <= n; len++){
        for (int i = 1; i <= n - len; i++){
            int j = len + i;
            for (int k = i; k < j; k++){
                if(sum[i][k] == sum[k+1][j] && sum[i][k] != 0){
                    sum[i][j] = sum[i][k] + 1;
                }
            }
        }
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        dp[i] = dp[i - 1] + 1;
        for (int j = 1; j <= i; j++){
            if(sum[j][i] > 0){
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    cout << dp[n] << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
```

