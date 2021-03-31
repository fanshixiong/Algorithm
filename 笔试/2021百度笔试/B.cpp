#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
#define pi pair<int, int>
int n, m;
int a[maxn][11];
void solve(){
	cin >> n >> m;
	int l, r;
	for(int i = 0; i < m; i++){
		int k; cin >> k;
		while(k--){
			cin >> l >> r;

			a[l][i]++; a[r+1][i]--;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < m; j++) a[i][j] += a[i-1][j];
	}

	vector<int> ans;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		bool flag = false;
		for(int j = 0; j < m; j++) if(a[i][j] == 0){
			flag = true;
			break;
		}
		if(flag) continue;
		cnt++;
		ans.emplace_back(i);
	}

	cout << cnt << endl;
	for(auto c : ans) cout << c << " ";
	cout << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}