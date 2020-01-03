#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int a[maxn], dp[maxn];
void solve(){
    int n, p, k;
    cin >> n >> p >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++){
        dp[i] = dp[i - 1] + a[i];
        if(i-k >= 0){
            dp[i] = min(dp[i], dp[i - k] + a[i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if(dp[i] <= p)
            ans = i;
    }
    cout << ans << endl;
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