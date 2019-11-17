#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxn = 100005;
vector<vector<int> > dp(maxn, vector<int> (2));
vector<vector<int> > father(maxn);
vector<bool> vis(maxn);
int N;
void dfs(int root){
	vis[root] = 1;
	for (int i = 0; i < father[root].size(); i++){
		int x = father[root][i];
		if (!vis[x]){
			dfs(x); 
			dp[root][0] += max(dp[x][0], dp[x][1]);
			dp[root][1] += dp[x][0];
		}
	}
}
int main(){
	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> dp[i][1];
	}
	int fa, son;
	cin >> fa >> son;
	while (fa != 0 && son != 0){
		father[fa].push_back(son);
		father[son].push_back(fa);  
		cin >> fa >> son;
	}
	dfs(1);
	cout << max(dp[1][0], dp[1][1]) << endl;
	return 0;
} 
