#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 8e7 + 10;
const ll mod = 1e9 + 7;
ll p[maxn];
bool v[maxn]; 
int n;
ll qsm(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res % mod;
}
ll calc(int i){
	if(i == 2) return qsm(2, log(n / 3) / log(2));
	return qsm(i, log(n / 2) / log(i));
}
void solve(){
	cin >> n;
	memset(v, false, sizeof v);
	int cnt = 0;
	ll ans = 1;
	for(int i = 2; i <= n / 2; i++){
		if(!v[i]){
			p[cnt++] = i;
			ans = (ans * calc(i)) % mod;
		}
		for(int j = 0; j < cnt && i * p[j] <= n / 2; j++){
			v[i * p[j]] = 1;
			if(i % p[j] == 0) break;
		}
	}
	if(ans == 1) cout << "empty" << endl;
	else cout << ans << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}