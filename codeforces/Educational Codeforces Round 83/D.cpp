#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int mod = 998244353;
const int maxn = 2e5 + 10;
ll fact[maxn];

ll qsm(ll a, ll b){
    ll ans = 1;
    a %= mod;
    while(b){
        if(b & 1){
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans % mod;
}


ll comb(int m, int n){
    return 1ll * (fact[m] * qsm((fact[n] * fact[m - n]) % mod, mod - 2)) % mod;
}

void solve(){
    int n, m;
    cin >> n >> m;
    if(n == 2 || n - 1 > m){
        cout << 0 << endl;
        return;
    }
    ll a = comb(m, n - 1) % mod;
    //cout << a << endl;
    ll b = (n - 2) % mod;
    //cout << b << endl;
    ll c = qsm(2, n - 3);
    //cout << c << endl;
    ll ans = (((a * b) % mod) * c) % mod;
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    fact[0] = 1;
    for (int i = 1; i < maxn; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }
    solve();
    return 0;
}