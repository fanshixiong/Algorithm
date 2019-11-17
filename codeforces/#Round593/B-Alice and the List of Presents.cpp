#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn = 1e9+7;
ll qsm(ll a, ll b){
	ll res = 1;
	while(b>0){
		if(b&1)
			res = (res*a)%maxn;
		a = (a*a)%maxn;
		b >>= 1;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	ll n, m;
	cin >> n >> m;
	ll ans = qsm(2, m);
	//cout << ans << endl;
	ans = qsm(ans-1, n);
	cout << ans << endl;
	return 0;
}
