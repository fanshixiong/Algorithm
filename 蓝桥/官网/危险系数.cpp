#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
vector<int> step(1000+5); 
int b=0;
class Train{
	int n;
	vector<bool> vis;
	vector<int> path;
	vector<vector<int> > G;
	int x0, y0;
public:
	Train(){
		int m;
		cin >> n >> m;
		G.resize(n+1);
		path.resize(n+1); 
		vis.resize(n+1);
		for(int i=0; i<m; i++){
			int x, y;
			cin >> x >> y;
			G[x].push_back(y); 
			G[y].push_back(x); 
		}
		cin >> x0 >> y0;
	}
	void dfs(int k){
		if(k==y0){
			step[k]++;b=1;
			for(int i=path[k]; i!=0; i=path[i]){
				step[i]++;
			}
		}
		for(int i=0; i<G[k].size(); i++){
			int t=G[k][i];
			if(!vis[t]){
				vis[t]=1;
				path[t]=k;
				dfs(t);
				vis[t]=0;
			}
		}
	}
	void resolve(){
		vis[x0]=1;
		dfs(x0);
		int ans=0;
		int tmp=step[x0];
		for(int i=1; i<=n; i++){
			//cout << step[i] << " ";
			if(step[i]==tmp)
				ans++;
		}
		if(!b)
			cout << -1 << endl;
		else
		 	cout << ans-2 << endl;
	}
};
int main(){
	Train test;
	test.resolve();
	return 0;
} 
