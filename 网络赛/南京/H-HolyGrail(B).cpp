#include<bits/stdc++.h>
using namespace std;

//SPFA

struct node{
	int v, w;
	node(int vi, int wi){
		v = vi;
		w = wi;
	}
};
const int maxn = 300+10;
vector<vector<node> > G(maxn);
int n, m;
int dist[maxn];
bool vis[maxn];

int spfa(int ui){
	memset(vis, 0, sizeof(vis));
	for(int i=0; i<n; i++)
		dist[i] = 0x3f3f3f3f;
	vis[ui] = 1;
	dist[ui] = 0;
	queue<int> q;
	q.push(ui);
	while(!q.empty()){
		int t = q.front();
		q.pop();
		vis[t]=0;
		for(int i=0; i<G[t].size(); i++){
			int tp = G[t][i].v;
			if(dist[tp] > dist[t] + G[t][i].w){
				dist[tp] = dist[t] + G[t][i].w;
				if(!vis[tp]){
					vis[tp] = 1;
					q.push(tp);
				}
			}
		}
	}
}
void solve(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		G[i].clear();
	}
	while(m--){
		int u, v, w;
		scanf("%d%d%d", &u,&v,&w);
		G[u].push_back(node(v, w));
	}
	for(int i=0; i<6; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		spfa(v);
		printf("%d\n", -dist[u]);
		G[u].push_back(node(v, -dist[u]));
	}
	
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
