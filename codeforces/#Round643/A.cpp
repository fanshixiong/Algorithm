#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
ll calc(ll n){
    ll imax = 0, imin = 1e18;
    while(n){
        ll t = n % 10;
        imax = max(t, imax);
        imin = min(t, imin);
        n /= 10;
    }
    return imax * imin;
}
void solve(){
    ll n, k; cin >> n >> k;
    while(--k){
        ll x = calc(n);
        if(!x) break;
        n += x;
    }
    cout << n << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}