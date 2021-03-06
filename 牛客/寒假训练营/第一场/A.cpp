#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 1e6 + 10;
const ll mod = 1e9 + 7;
ll f[maxn];
ll qsm(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res % mod;
}
/*
void solve(){
	int n; cin >> n;
	f[0] = 0; f[1] = 0;
	for(int i = 2; i <= n; i++){
		f[i] = ((qsm(26, i-1)-qsm(25, i-1) + mod) % mod + f[i-1] * 25 % mod) % mod;
	}
	ll ans = 0;
	for(int i = 0; i <= n; i++) ans = (ans + f[i]) % mod;
	cout << ans << endl;
}
*/
ll a[maxn][3];
void solve(){
	int n; cin >> n;
	a[0][0] = a[0][1] = a[0][2] = 0;
	a[1][0] = 25; a[1][1] = 1; a[1][2] = 0;
	for(int i = 2; i <= n; i++){
		a[i][0] = a[i-1][0] * 25 % mod;
		a[i][1] = (a[i-1][0] + a[i-1][1] * 25 % mod) % mod;
		a[i][2] = (a[i-1][1] + a[i-1][2] * 26 % mod) % mod;
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) ans = (ans + a[i][2]) % mod;
	cout << ans << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}