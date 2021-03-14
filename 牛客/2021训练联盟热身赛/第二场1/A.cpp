#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
void solve(){
	ll a = 1, x; cin >> x;
	cout << "Input value: " << x << endl;

	for(int i = 1; i <= 100; i++){
		if(a >= x){
			cout << a << endl << endl;
			return;
		}
		a *= 2;
	}
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}