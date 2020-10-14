#include<bits/stdc++.h>

using namespace std;

#define ll unsigned long long

const int maxn = 1e4+10;

vector<int> G[maxn];
int ans[maxn];
int vis[maxn];
int n, m;

void dfs(int u, int val){
	memset(vis, 0, n * 8 + 100);
	vis[u] = 1;
	ans[u] += val;
	queue<int> q;
	q.push(u);

	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int i = 0; i < G[v].size(); i++){
			int x = G[v][i];
			if(vis[x]) continue;
			q.push(x);
			vis[x] = 1;
			ans[x] += val;
			//cout << x << "  " << ans[x] << endl;
		}
	}
}

int main(){
	freopen("J.txt", "r", stdin);
	cin >> n >> m;
	memset(ans, 0, sizeof ans);
	while(m--){
		int t, a, b;
		cin >> t >> a >> b;
		if(t == 1){
			G[a].push_back(b);
			G[b].push_back(a);
		}else{
			dfs(a, b);
		}
	}
	
	// for(int i = 0; i < G[2].size(); i++) cout << G[2][i] << " " ;
	
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << endl;
	return 0;
}

