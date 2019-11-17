/*leetcode: 找出网格中有多少从左上到右下的方案数
分析： 搜索，时间复杂度太高           考虑dp 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int d[2][2] = {0, 1, 1, 0}; 
class Robot{
	int M,N;
	vector<vector<bool> > vis;
	int res;
public:
	Robot(){
		cin >> M >> N;
		vis.resize(M);
		for (int i = 0; i < M; i++){
			vis[i].resize(N);
		}
		res = 0;
	}	
	bool judge(int x, int y){
		if (x < 0 || y < 0 || x >= M || y >= N)
			return false;
		return true;
	}
	void dfs(int x, int y){
		if (x == M-1 && y == N - 1 && !vis[x][y]){
			res++;
			return;
		}
		vis[x][y] = true;
		for(int i = 0; i < 2; i++){
			int x1 = x + d[i][0];
			int y1 = y + d[i][1];
			if (judge(x1, y1) && !vis[x1][y1])
				dfs(x1, y1);
		}
		vis[x][y] = false;
	}
	int returnres(){
		dfs(0, 0);
		return res;
	}
};
/*
int main(){
	Robot test;
	cout << test.returnres() << endl;
	return 0;
}*/

int main(){
	int m, n;
	cin >> m >> n;
	vector<vector<int> > dp(m, vector<int> (n, 1));
	for (int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
	cout << dp[m-1][n-1] << endl;
	return 0;
}
