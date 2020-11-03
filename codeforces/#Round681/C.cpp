#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int ans[maxn];

void solve(){
    ll p, q;
    cin >> p >> q;
    if(p % q) {
        cout << p << endl;
        return;
    }
    ll ans = 0;
    for (ll i = 1; i * i <= q; i++){
        if(q % i) continue;
        ll t = p;
        if(i != 1){
            while(t % q == 0) t/=i;
            ans = max(ans, t);
        }
        t = p;
        while(t % q == 0) t /= (q/i);
        ans = max(ans, t);
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