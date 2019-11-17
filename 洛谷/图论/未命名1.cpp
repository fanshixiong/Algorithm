#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
vector<int> par(405);
bool vis[405];
vector<vector<int> > G(405);
int n, m, e;
void declare(){
	for(int i=0; i<405; i++)
		par[i]=0;
	for(int i=0; i<405; i++)
		G[i].clear(); 
}
void init(){
	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			int x;
			cin >> x;
			if(x==1){
				G[i].push_back(j+n); 
			}
		}
	}
}
bool dfs(int k){
	for(int i=0; i<G[k].size(); i++){
		int t=G[k][i];
		if(!vis[t]){
			vis[t]=1;
			if(!par[t] || dfs(par[t])){
				par[t]=k;
				return true;
			}
		}
	}
	return false;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		declare();
		init();
		int ans=0;
		for(int i=1; i<=n; i++){
			memset(vis, 0, sizeof(vis));
			if(dfs(i))
				ans++;
		}
		if(ans >= n)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
