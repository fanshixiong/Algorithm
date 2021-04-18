#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int a[maxn], b[maxn];
void solve(){
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];		

	for(int i = 1; i <= m; i++) cin >> b[i];

	int sums = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) sums = sums ^ (a[i] ^ b[j]);
	}

	int sum = 0;
	for(int i = 1; i <= m; i++) sum ^= b[i];

	cout << sums << " " << sum << endl;
}
/*
5
4 4
1 2 3 4
3 4 5 6
*/
int main(){
	cout << (12 ^ 4) << endl;
	int t; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}