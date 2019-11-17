#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
int maxn = 100005;
int mod = 10007;
vector<vector<int> > father(maxn);
vector<vector<int> > dp(maxn, vector<int> (3));
void dfs(int root){
	dp[root][0] = dp[root][1] = 0;
	int x0 = 1, x1 = 1;
	for (int i = 0; i < father[root].size(); i++){
		int x = father[root][i];
		dfs(x);
		x0 = (x0 * (dp[x][0]+dp[x][1]))%mod;
		x1 = (x1 * dp[x][0])%mod;
	}
	dp[root][0] = (x0+dp[root][0])%mod;
	dp[root][1] = (x1+dp[root][1])%mod;
}
int main(){
	cin >> N;
	for (int i = 2; i <= N; i++){
		int x;
		cin >> x;
		father[x].push_back(i); 
	}
	dfs(1);
	cout << dp[1][0] + dp[1][1] -1 << endl;
	return 0;
}
