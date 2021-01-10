#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 5e2 + 10;
int a[maxn][maxn], dp[maxn][maxn];
void solve(){
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++) cin >> a[i][j];
    }

    memset(dp, -0x3f3f3f3f, sizeof dp);
    dp[1][1] = a[1][1];
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
        }
    }
    int ans = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[n][i]);
    cout << ans << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}