#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 10005;
ll fac[maxn];


ll qpow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1){
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
ll C(ll m, ll n){
    if(m>n || m <0)
        return 0;
    ll f1 = fac[n], f2 = fac[m] * fac[n - m] % mod;
    return f1 * qpow(f2, mod - 2) % mod;
}
int main(){
    ios_base::sync_with_stdio(0);
    fac[0] = 1;
    for (int i = 1; i < maxn; i++)
        fac[i] = fac[i - 1] * i % mod;
    ll n, m;
    cin >> n >> m;
    ll ans = C(n - 1, 2 * m + n - 1) % mod;
    cout << ans << endl;
    return 0;
}