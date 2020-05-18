/*
    设:
    f[i][0] 表示前i个合法，并且第i个字符为0的最小操作次数
    f[i][1] 表示前i个合法，并且第i个字符为1的最小操作次数

    状态转移方程:
        f[i][0]=min(f[i-1][0],f[i-1][1])+(s[i] == ‘1’)
    f[i][0]合法只需要i-1合法就行
        f[i][1]=min(pre[i-1],f[i-k][1]+pre[i-1]-pre[i-k])+(s[i] ==‘0’)
    f[i][1]合法只需要i-k的状态合法。    
    如果i~k之间还存在1，那么我们肯定要把i ~ k之间的1给删掉 需要的代价为pre[i-1]-pre[i-k]
    或者把i之前的1都删除 需要的代价就是 pre[i-1]
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 1e6 + 10;
string s;
int pre[maxn];
int dp[maxn][3];
void solve(){
    int n, k; cin >> n >> k;
    cin >> s;
    pre[0] = 0;
    for (int i = 1; i <= n; i++) pre[i] = pre[i-1] + (s[i-1] - '0');
    for (int i = 1; i <= n; i++) dp[i][0] = dp[i][1] = 0x3f3f3f3f;
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; i++){
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + (s[i - 1] == '1');
        dp[i][1] = min(pre[i - 1], dp[max(0, i - k)][1] + pre[i - 1] - pre[max(0, i - k)]) + (s[i - 1] == '0');
    }
    cout << min(dp[n][0], dp[n][1]) << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}