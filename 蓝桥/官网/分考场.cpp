#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;
int n;
vector<int> vis(101);
vector<int> f(101);
vector<vector<int> > G(101);
int ans=0;
void dfs(int k, int step){
	vis[k]=1;
	f[k]=step;
	for(int i=0; i<G[k].size(); i++){
		int t=G[k][i];
		if(!vis[t]){
			dfs(t, step+1);
		}
		else{
			ans=max(ans, f[k]-f[t]+1);
		}
	}
}
int main(){
	int k;
	cin >> n >> k;
	
	for(int i=0; i<k; i++){
		int x, y;
		cin >> x >>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	
	for(int i=1; i<=n; i++)
		if(!vis[i])
			dfs(i, 1);
	cout << ans <<endl;
	return 0;
}
