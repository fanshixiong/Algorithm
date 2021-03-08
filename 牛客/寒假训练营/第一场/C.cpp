#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 3e5 + 10;
const ll mod = 1e9 + 7;
int n, cnt = 0;
vector<int> G[maxn];
int col[maxn], vis[maxn];
bool flag = false;
void dfs(int u, int fa){
	int count = 0;
	for(auto v : G[u]){
		if(v == fa) continue;
		count ++;
		dfs(v, u);
	}
	if(count == 0 || !vis[u]){
		if(vis[fa]) {flag = true; return;}
		vis[u] = vis[fa] = ++cnt;
	}
}
void dfs2(int u, int fa){
	for(auto v : G[u]){
		if(v == fa) continue;
		if(vis[v] == vis[u]) col[v] = col[u];
		else col[v] = col[u] ^ 1;
		dfs2(v, u);
	}
}
void solve(){
	cin >> n;
	int x, y;
	for(int i = 1; i < n; i++){
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	memset(vis, 0, sizeof vis);
	dfs(1, 0);

	if(flag || vis[0] != 0) {
		cout << -1 << endl;
		return;
	}
	//for(int i = 1; i <= n; i++) cout << vis[i] << " ";
	//cout << endl;

	col[1] = 1;
	dfs2(1, 0);
	for(int i = 1; i <= n; i++) cout << (col[i] == 1 ? 'R' : 'B');
	cout << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}