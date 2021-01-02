#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 1e7 + 10;
const ll mod = 1023694381;

int n, m, L, R;
ll fact[maxn], infact[maxn];
ll qpow(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}

	return ans;
}

ll C(ll n, ll m){
	if(m == 0 || n == m) return 1ll;
	return fact[n] * infact[m]  % mod * infact[n-m] % mod;
}
void solve(){
    cin >> n >> m;
    R = max(n, m);
    L = min(n, m);

    fact[1] = 1ll;
    for(int i = 2; i <= R; i++) fact[i] = fact[i-1] * 1ll * i % mod;
	
	infact[R] = qpow(fact[R], mod - 2);
    for (int i = R - 1; i; i--) infact[i] = infact[i + 1] * 1ll * (i + 1) % mod;

    ll sums = qpow(m, n);
	for(int i = 0; i < L; i++){
		sums = (sums + mod - C(1ll*(n-1), 1ll*i) * C(1ll*m, 1ll*(i+1)) % mod * fact[i+1] % mod) % mod;
	}
	cout << sums << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}