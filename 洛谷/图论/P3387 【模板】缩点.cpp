#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
vector<vector<int> > G(10007), G1(10007);
vector<int> color(10008), dfn(10008), low(10008), num(10008), weight(10009);
vector<int> in(20007), dist(100098);
int col, cnt, n, m;
vector<bool> vis(10008);
stack<int> s;
void tarjan(int k){
	dfn[k] = low[k] = ++cnt;
	vis[k]=1;
	s.push(k);
	for(int i=0; i<G[k].size(); i++){
		int t=G[k][i];
		if(!dfn[t]){
			tarjan(t);
			low[k] = min(low[k], low[t]);
		}
		else if(vis[t]){
			low[k] = min(low[k], low[t]);
		}
	}
	if(dfn[k] == low[k]){
		color[k] = ++col;
		vis[k] = 0;
		num[col] += weight[k];
		while(s.top() != k){
			color[s.top()] = col;
			num[col] += weight[s.top()];
			vis[s.top()]=0;
			s.pop();
		}
		s.pop();
	}
}
void dfs(int k){ //****virtal
	if(dist[k]) 
		return;
	dist[k] = num[k];
	int ans = 0;
	for(int i=0; i<G1[k].size(); i++){
		int t = G1[k][i];
		if(!dist[t])
			dfs(t);
		ans = max(ans, dist[t]);
	}
	dist[k] += ans;
}
int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> weight[i];
	}
	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
	}
	for(int i=1; i<=n; i++){
		if(!dfn[i])
			tarjan(i);
	}
	for(int i=1; i<=n; i++){
		for(int j=0; j<G[i].size(); j++){
			int t=G[i][j];
			if(color[i] != color[t]){
				G1[color[i]].push_back(color[t]);
			}
		}
	}
	int ans = 0;
	for(int i=1; i<=col; i++){
		if(!dist[i]){
			dfs(i);
			ans = max(ans, dist[i]);
		}
	}
	cout << ans << endl;
	return 0;
} 
