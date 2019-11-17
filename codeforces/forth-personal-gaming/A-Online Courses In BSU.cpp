#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector> 
using namespace std;
const int maxn = 1e5+5;
vector<vector<int> > G(maxn);
int n, m, k, ans=0;
vector<int> num(maxn), res;
vector<int> vis(maxn, 0);
bool dfs(int t){
	vis[t] = -1;
	for(int i=0; i<G[t].size(); i++){
		int s = G[t][i];
		if(vis[s] == -1)
			return false;
		else if(!vis[s] && !dfs(s))
			return false;
	}
	vis[t]=1;
	res.push_back(t);
	return true;
}
bool topo(){
	for(int i=0; i<k; i++){
		if(!vis[num[i]] && !dfs(num[i]))
			return false;
	}
	return true;
}
int main(){
	cin >> n >> k;
	for(int i=0; i<k; i++){
		cin >> num[i];
	}
	for(int j=1; j<=n; j++){
		int t; 
		cin >> t;
		for(int i=1; i<=t; i++){
			int tmp; cin >> tmp;
			G[j].push_back(tmp);
		}
	}
	
	if(topo()){
		ans = res.size();
		cout << ans <<endl;
		for(int i=0; i<ans-1; i++){
			cout << res[i] << " ";
		}
		cout << res[ans-1] << endl;
	}
	else{
		cout << -1 << endl;
	}
	return 0;
} 
