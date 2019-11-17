#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int q, n;
int step=0, col=0, ans=0;
vector<vector<int> > graph(maxn);
int low[maxn], dfn[maxn], color[maxn], cnt[maxn];
bool vis[maxn];
stack<int> s;
void tarjan(int k){
	dfn[k]=++step;
	low[k]=step;
	vis[k]=1;
	s.push(k);
	for(int i=0; i<graph[k].size(); i++){
		int t=graph[k][i];
		if(!dfn[t]){
			tarjan(t);
			low[k]=min(low[t], low[k]);
		}
		else if(vis[t]){
			low[k]=min(low[t], low[k]);
		}
	}
	if(dfn[k]==low[k]){
		color[k]=++col;
		vis[k]=0;
		while(s.top()!=k){
			color[s.top()]=col;
			vis[s.top()]=0;
			s.pop();
		}
		s.pop();
	}
}
void solve(){
	memset(dfn, 0, sizeof(dfn));
	memset(color, 0, sizeof(color));
	memset(vis, 0, sizeof(vis));
	memset(low, 0, sizeof(low));
	memset(cnt, 0, sizeof(cnt));
	for(int i=0; i<=n; i++)
		graph[i].clear();
	step=0; col=0; ans=0;
	for(int i=1; i<=n; i++){
		int x;
		cin >> x;
		graph[i].push_back(x);
	}
	for(int i=1; i<=n; i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	for(int i=1; i<=n; i++){
		cnt[color[i]]++;
		//cout << i << "  " << color[i] << endl;
	}
	for(int i=1; i<n; i++){
		cout << cnt[color[i]] << " ";
	}
	cout << cnt[color[n]] << endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin >> q;
	while(q--){
		cin >> n;
		solve();
	} 
	return 0;
}
