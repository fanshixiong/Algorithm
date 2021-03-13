#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
const int maxn = 1e5+10;
int n, m;
int a[maxn];
vector<int> G[maxn];
bool vis[maxn];
int bfs(int u){
	memset(vis, 0, sizeof vis);
	vis[u] = 1;
	queue<pi> q;
	q.push({u, 1});
	int dist = 0;
	while(!q.empty()){
		auto x = q.front(); q.pop();
		int u = x.first, d = x.second;
		dist = max(dist, d);
		for(auto v : G[u]){
			if(vis[v] || a[v] >= a[u]) continue;
			q.push({v, d+1});
			vis[v] = 1;
		}
	}
	return dist;
}
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int maxx = 0, p;
	for(int i = 1; i <= n; i++){
		if(a[i] > maxx) maxx = a[i], p = i;
	}
	// cout << bfs(p) << endl;;
	int mx = 0;
	for(int i = 1; i <= n; i++){
		if(maxx = a[i]) mx = max(mx, bfs(i));
	}
	cout << mx << endl;
	return 0;
}