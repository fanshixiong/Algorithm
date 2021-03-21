#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
void solve(){
	ll m, n;
	cin >> m >> n;
	ll x = __gcd(m, n);
	ll a = m / x, b = n / x;
	if((a & 1) && (b & 1)){
		cout << x << endl;
	}
	else{
		cout << 0 << endl;
	}
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}