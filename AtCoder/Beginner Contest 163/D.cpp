#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
void solve(){
    ll n, k; cin >> n >> k;
    if(n == k-1){ cout << 1 << endl;
        return;
    }
    ll ans = 0;
    for(ll i = k; i <= n + 1; i++){
        ll minn = (i - 1) * i / 2;
        ll maxx = (2 * n - i + 1) * i / 2;
        ans = (ans + maxx - minn + 1) % mod;
    }
    cout << ans << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}