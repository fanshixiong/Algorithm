#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];
void solve(){
    ll a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;

    ll ans = 1e18;
    for (int i = 0; i<2; i++){
        ll da = min(n, a - x);
        ll db = min(n - da, b - y);

        ans = min(ans, 1ll * (a - da) * (b - db));
        swap(a, b);
        swap(x, y);
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