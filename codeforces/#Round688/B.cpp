#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
ll a[maxn], c[maxn];
int n;
void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll ans = 1e18;
    
    ll sums = 0;
    for(int i = 2; i <= n; i++)  c[i] = abs(a[i]-a[i-1]), sums += c[i];

    for(int i = 2; i < n; i++){
        ans = min(ans, sums - c[i] - c[i + 1] + abs(a[i+1] - a[i-1]));
        // cout << c[i] << " " << sums - c[i] - c[i + 1] + abs(a[i+1] - a[i-1]) << endl;
    }
    ans = min(ans, sums - c[2]);
    ans = min(ans, sums - c[n]);

    cout << ans << endl;
}  
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}