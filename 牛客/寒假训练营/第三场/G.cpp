#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 1e6 + 10;
const ll mod = 1e9 + 7;
int par[maxn];
ll a[maxn], var[maxn];
int n, m;
void init(){
	for(int i = 0; i <= n; i++) par[i] = i, var[i] = 0;
}
int Find(int x){
	if(x == par[x]) return x;
	return par[x] = Find(par[x]);
}
void Union(int x, int y){
	x = Find(x), y = Find(y);
	par[x] = y;
}
void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];

	init();
	int x, y;
	for(int i = 1; i <= m; i++){
		cin >> x >> y;
		Union(x, y);
	}
	for(int i = 1; i <= n; i++){
		int t = Find(i);
		var[t] = max(var[t], a[i]);
	}
	/*
	for(int i = 1; i <= n; i++){
		cout << par[i] << " " << var[i] << endl;
	}*/
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		int t = Find(i);
		if(var[t]) ans += var[t];
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