#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> par(10005),stu(10005), gohome(10005);
vector<vector<int> > G(105, vector<int>(105));
vector<bool> vis(10005);
int n;
bool dfs(int k){
	for(int i=1; i<=n; i++){
		if(!vis[i] && G[k][i] && stu[i]){
			vis[i]=1;
			if(!par[i] || dfs(par[i])){   //dfs(i)
				par[i]=k;
				return true;
			}
		}
	}
	return false;
}
bool judge(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)
			vis[j]=0;
		if((!stu[i] || !gohome[i]) && !dfs(i))
			return false;
	}
	return true;
}
int main(){
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=1; i<=n; i++){
			par[i]=0; stu[i]=0; gohome[i]=0;
			vis[i]=0;
		}
		for(int i=1; i<=n; i++)
			cin >> stu[i];
		for(int i=1; i<=n; i++){
			cin >> gohome[i];
			if(!stu[i])
				gohome[i]=1;
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				cin >> G[i][j];
			}
			if(stu[i])
				G[i][i]=1;
		}
		if(judge())
			cout << "^_^" << endl;
		else
			cout << "T_T" << endl;
	}
	return 0;
}
