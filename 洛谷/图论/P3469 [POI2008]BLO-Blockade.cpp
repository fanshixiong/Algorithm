#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
vector<vector<int> > G(100007);
vector<int> dfn(100008), low(100008), size(100008);
int col, cnt, n, m;
vector<long long> ans(100008);
void tarjan(int k, int p){
	int sz = 1, ua = 0;
	dfn[k] = low[k] = ++cnt;
	for(int i=0; i<G[k].size(); i++){
		int t=G[k][i];
		if(t == p) continue;
		if(!dfn[t]){
			tarjan(t, k);
			low[k] = min(low[k], low[t]);
			sz += size[t];
			if(low[t] >= dfn[k]){
				ua += size[t];
				ans[k] += (long long)2*size[t]*(n-ua-1);	
			}
		}
		else{
			low[k] = min(low[k], low[t]);
		}
	}	
	size[k] = sz;
	ans[k] += 2*(n-1);
}
int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	tarjan(1, 0); 
	for(int i=1; i<=n; i++)
		cout << ans[i] << endl;
	return 0;
} 
