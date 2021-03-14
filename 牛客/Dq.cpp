#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int n, m;
int a[maxn];
vector<int> G[maxn];
int dp[maxn][2];
bool vis[maxn];
int f0[maxn], f1[maxn];
void dfs(int u){
	dp[u][0] = a[u]; dp[u][1] = 0;
	// f0[u] = 1;
	for(auto v : G[u]){
		if(vis[v]) continue;
		vis[v] = 1;
		dfs(v);
		dp[u][0] += dp[v][1];
		f0[v] = 1;
		dp[u][1] += max(dp[v][0], dp[v][1]);
		if(dp[v][0] > dp[v][1]) f0[v] = 1;
		else f1[v] = 1;
		vis[v] = 0;
	}
}
int main(){
	cin >> n >> m;
	memset(dp, 0, sizeof dp);
	memset(vis, 0, sizeof vis);
	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	vis[1] = 1;
	dfs(1);
	int ans = max(dp[1][1], dp[1][0]);
	int minn = 0x3f3f3f3f;
	if(dp[1][1] > dp[1][0]) {
		for(int i = 1; i <= n; i++){
			if(!f1[i]) continue;
			minn = min(minn, a[i]);
		}
	}
	else{
		for(int i = 1; i <= n; i++){
			if(f1[i]) continue;
			minn = min(minn, a[i]);
		}
	}

	cout << ans << " " << minn << endl;
	return 0;
}