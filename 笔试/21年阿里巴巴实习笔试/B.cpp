#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
int n, m;
int a[maxn];
int sums, ans;
void dfs(int p, int cur){
	if(cur % m == 0) ans = max(ans, cur);
	if(p == n){
		if((cur + a[p]) % m == 0) ans = max(ans, cur + a[p]);
		return;
	}

	dfs(p+1, cur);
	for(int i = p+1; i <= n; i++) dfs(i, cur + a[p]);
}
void solve(){
	cin >> n >> m;
	sums = ans = 0;
	for(int i = 1; i <= n; i++) cin >> a[i], sums += a[i];

	dfs(1, 0);
	cout << sums - ans << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}