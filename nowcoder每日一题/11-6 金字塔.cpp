/*
https://ac.nowcoder.com/acm/problem/51172
区间DP
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const int mod = 1e9;
ll dp[350][350];
void solve(){
    string s; cin >> s;
    int n = s.size();
    for (int i = 1; i <= n; i++) dp[i][i] = 1;

    for (int l = 1; l <= n; l++)
        for (int i = 1; i + l <= n; i++){
            int j = i + l;
            if(s[i-1] != s[j-1]) continue;
            dp[i][j] += dp[i + 1][j - 1];
            for (int k = i + 1; k < j; k++)
                if(s[k-1] == s[j-1]) dp[i][j] = (dp[i][j] + dp[i + 1][k - 1] * dp[k][j] % mod) % mod;
        }
    cout << dp[1][n] << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}