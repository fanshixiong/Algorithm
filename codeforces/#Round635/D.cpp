#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 4e5 + 10;
ll a[maxn], b[maxn], c[maxn];
ll f(ll a, ll b, ll c){
    return (a - b) * (a - b) + (a - c) * (a - c) + (b - c) * (b - c);
}

void solve(){
    ll x, y, z; cin >> x >> y >> z;
    for(int i = 0; i < x; i++) cin >> a[i]; sort(a, a + x);
    for(int i = 0; i < y; i++) cin >> b[i]; sort(b, b + y);
    for(int i = 0; i < z; i++) cin >> c[i]; sort(c, c + z);
    ll ans = 2e18 + 7;
    for(int i = 0; i < x; i++){
        int py = lower_bound(b, b + y, a[i]) - b;
        int pz = lower_bound(c, c + z, a[i]) - c;
        if(py == y) py--;
        if(pz == z) pz--;
        if(py > 0) ans = min(ans, f(a[i], b[py - 1], c[pz]));
        if(pz > 0) ans = min(ans, f(a[i], b[py], c[pz - 1]));
        ans = min(ans, f(a[i], b[py], c[pz]));
    }
    for(int i = 0; i < y; i++){
        int px = lower_bound(a, a + x, b[i]) - a;
        int pz = lower_bound(c, c + z, b[i]) - c;
        if(px == x) px--;
        if(pz == z) pz--;
        if(px > 0) ans = min(ans, f(a[px - 1], b[i], c[pz]));
        if(pz > 0) ans = min(ans, f(a[px], b[i], c[pz - 1]));
        ans = min(ans, f(a[px], b[i], c[pz]));
    }
    for(int i = 0; i < z; i++){
        int px = lower_bound(a, a + x, c[i]) - a;
        int py = lower_bound(b, b + y, c[i]) - b;
        if(px == x) px--;
        if(py == y) py--;
        if(px > 0) ans = min(ans, f(a[px - 1], b[py], c[i]));
        if(py > 0) ans = min(ans, f(a[px], b[py - 1], c[i]));
        ans = min(ans, f(a[px], b[py], c[i]));
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