#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int a[maxn];
void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	unordered_map<int, int> p;
	for(int i = 0; i < n; i++) p[a[i]]++;

	int ans = 0x3f3f3f3f;
	for(int i = 0; i < n; i++) if(p[a[i]] == 1) ans = min(ans, a[i]);\

	if(ans == 0x3f3f3f3f) cout << -1 << endl;
	else cout << ans << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}