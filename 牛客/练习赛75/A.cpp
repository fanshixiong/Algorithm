//https://oi-wiki.org/math/quick-pow/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1e9+7;
ll a, b, m, n;
ll qpow(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans % mod;
}
void solve(){
    cin >> a >> b >> m >> n;
    ll f1 = 1, f2 = 1, fn = 1;
    for(int i = 3; i <= n; i++){
    	fn = (a * f1 + b *  f2)  % (mod - 1); // 为什么是mod-1？ 费马小定理
    	f2 = f1;
    	f1 = fn;
    	// cout << f1 << " " << f2 << endl;
    }
    cout << fn << endl;
    cout << qpow(m, fn) << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}