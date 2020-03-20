# [codeforces EDC Round82 E - EraseSubsequences](https://codeforces.com/contest/1303/problem/E)

数据范围只有$400$，所以可以使用$O(n^3)$的写法。

$dp[i][j]$表示在 $s$ 的第 $i $个位置（从$1$开始）和 $t_1$ 的第 $j$ 个位置，能够满足的 $t_2$ 的最大距离。

状态转移方程$dp[i][j]=\begin{cases}dp[i-1][j]\\dp[i-1][j-1]　(s[i-1]==t1[j-1])\\dp[i-1][j]+1　(s[i-1]==t2[j-1])\end{cases}$

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;

int dp[410][410];
bool judge(string s, string t1, string t2){
    int slen = s.size(), t1len = t1.size(), t2len = t2.size();
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < slen; i++){
        for (int j = 0; j <= t1len; j++){
            if(dp[i][j]>=0){
                if(j<t1len && s[i] == t1[j]){
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
                }
                if(dp[i][j]<t2len && s[i] == t2[dp[i][j]]){
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]+1);
                }
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            }
        }
    }
    return dp[slen][t1len] >= t2len;
}
void solve(){
    string s, t;
    cin >> s >> t;
    int slen = s.size(), tlen = t.size();
    bool flg = 0;
    for (int i = 0; i < tlen; i++){
        if(judge(s, t.substr(0, i), t.substr(i, tlen-i))){
            flg = 1;
            break;
        }
    }
    if (flg)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```

