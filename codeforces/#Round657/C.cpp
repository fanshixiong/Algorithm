#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
ll m, n;
ll a[maxn], b[maxn], c[maxn], sum[maxn];
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> a[i] >> b[i];
        c[i] = a[i];
    }
    sort(c + 1, c + 1 + m);
    for (int i = 1; i <= m; i++) sum[i] = sum[i-1] + c[i];
    ll ans = 0;
    c[m + 1] = 0x3f3f3f3f;
    for (int i = 1; i <= m; i++){
        ll len = m + 1 - (lower_bound(c + 1, c + 1 + m, b[i]) - c);
        len = min(len, n - 1);
        ll hap = a[i] + 1ll * b[i] * (n - 1 - len) + sum[m] - sum[m - len];
        if(a[i] >= c[m - len + 1]){ //把自己也加进去了
            hap -= a[i];
            hap += max(b[i], c[m - len]);
        }
        ans = max(ans, hap);
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