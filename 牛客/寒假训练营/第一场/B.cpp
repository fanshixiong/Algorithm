#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
void solve(){
	ll k; cin >> k;
	if(k == 0){
		cout << "(" << endl;
		return;
	}
	ll a = 1e9, b = 1e9, p = 1e9;
	for(ll i = 1; i * i <= k; i++){
		ll x = i, y = k / i, z = k - (i * (k / i));
		// cout <<  x << " " << y << " " << z << endl;
		if(x + y + z < a + b + p){
			a = x, b = y, p = z;
		}
	}
	string ans = "(";
	for(int i = 0; i < p; i++) ans += ")";
	for(int i = 0; i < a - 1; i++) ans += "(";
	for(int i = 0; i < b; i++) ans += ")";
	cout << ans << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}