#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const int mod = 998244353;
ll qpow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1)  ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans % mod;
}
void solve(){
    ll n, m, l, r;
    cin >> n >> m >> l >> r;
    ll x = (r - l + 1);
    if(n * m % 2 == 1){
        cout << qpow(x, n * m) % mod << endl;
        return;
    }
    //cout << x << " " << n * m << endl;
    ll ans = (qpow(x, n * m) + ((x & 1) ? 1 : 0)) % mod;
    //cout << ans << endl;   
    ans = (ans * qpow(2ll, mod - 2ll)) % mod;
    cout << ans << endl;
}
int main(){
    IOS;
    int t; t = 1;
    while(t--){
        solve();
    }
    return 0;
}