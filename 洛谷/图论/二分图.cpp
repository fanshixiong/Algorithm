#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
vector<int> par(2005);
bool vis[2005];
vector<vector<int> > G(2005);
int n, m, e;
void init(){
	cin >> n >> m >> e;
	for(int i=0; i<e; i++){
		int x, y;
		cin >> x >> y;
		if (x>=1&&y>=1&&x<=n&&y<=m)
			//G[x].push_back(y+n);  
			G[x].push_back(y+n); 
	}
}
bool dfs(int k){
	for(int i=0; i<G[k].size(); i++){
		int t=G[k][i];
		if(!vis[t]){
			vis[t]=1;
			if(!par[t] || dfs(par[t])){
				par[t]=k;
				//par[k]=t;   //¾ÞÀÐ¸æËßÎÒµÄ 
				return true;
			}
		}
	}
	return false;
}
int main(){
	init();
	int ans=0;
	for(int i=1; i<=n; i++){
		memset(vis, 0, sizeof(vis));
		if(dfs(i))
			ans++;
	}
	cout << ans << endl;
	return 0;
}
