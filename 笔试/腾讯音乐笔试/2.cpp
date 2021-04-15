#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn], b[maxn], p[maxn];
bool cmp(int x, int y){
	return a[x] == a[y] ? b[x] > b[y] : a[x] < a[y];
}
void solve(){
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];

	for(int i = 1; i <= n; i++) p[i] = i;

	sort(p, p + n, cmp);

	int ans = 0;
	unordered_map<int, int> ct;
	for(int i = 0; i < n; i++) ct[a[i]]++;
	int i = 0;
	while(i < n){
		int x = p[i];
		while(ct[a[x]] > 1){
			i++;
			ct[a[x]]--;
			int t = a[x];
			while(ct[t]) t++;
			ans += (t-a[x]) * b[x];
			ct[t] = 1;
		}
		i++;
	}
	cout << ans << endl;
}
int main(){
	int t; t = 1;
	while(t--){
		solve();
	}
	return 0;
}