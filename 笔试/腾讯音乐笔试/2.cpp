#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 10;
const ll mod = 1e9+7;
int a[maxn];
void solve(){
	string s; cin >> s;

	ll ans = 0, cnt = 0;
	for(int i = s.size()-1; i >= 0; i--){
		if(s[i] == 'b') cnt++;
		else{
			ans = (ans + cnt) % mod;
			cnt *= 2;
		}
	}
	cout << ans % mod << endl;
}
int main(){
	int t; t = 1;
	while(t--){
		solve();
	}
	return 0;
}