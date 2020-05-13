#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 1e6 + 10;
int s[maxn], dp[maxn];

void solve(){
    int n ; cin >> n ;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) dp[i] = 1;

    int ans = 1;
    for (int i = n; i >= 1; i--){
        dp[i] = 1;
        for (int j = 1; j * i <= n; j++){
            if(s[i] < s[i*j]){
                dp[i] = max(dp[i], dp[i * j] + 1);
            }
        }
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}