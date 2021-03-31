#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
int phi[maxn], pri[maxn];
bool vis[maxn];
int MAXN, cnt = 0;
void init() {
  	phi[1] = 1;
  	for (int i = 2; i <= MAXN; ++i) {
    	if (!vis[i]) {
      		phi[i] = i - 1;
      		pri[cnt++] = i;
    	}
    	for (int j = 0; j < cnt; ++j) {
      		if (1ll * i * pri[j] > MAXN) break;
      		vis[i * pri[j]] = 1;
      		if (i % pri[j]) {
        		phi[i * pri[j]] = phi[i] * (pri[j] - 1);
      		} else {
        		phi[i * pri[j]] = phi[i] * pri[j];
        		break;
      		}
    	}
  	}
}
ll qsm(ll a, ll b){
	ll res = 1;
  	while (b > 0) {
    	if (b & 1) res = res * a % mod;
    	a = a * a % mod;
    	b >>= 1;
  	}
  	return res % mod;
}
void solve(){
	ll n; cin >> n;
	MAXN = n;
	ll ans = 0;
	init();
	for(ll i = 2; i <= n; i++){
		ll t = 0, x = i;
		int j = 0;
		while(x > 1){
			// cout << pri[j] << " ";
			while(x % pri[j] == 0){
				t = (t * 10 + pri[j]) % mod;
				x /= pri[j];
				// cout << t << " ";
			}
			// cout << endl;
			j++;
		}
		ans = qsm(ans + t, mod);
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