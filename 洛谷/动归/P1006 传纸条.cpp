#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int dp[110][55][55]={0};
int main(){
	int m, n;
	cin >> m >> n;
	vector<vector<int> > G(m+1, vector<int>(n+1));
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++)
			cin >> G[i][j];
	}
	for(int sum=1; sum<=m+n; sum++){
		for(int i=1; i<=m; i++){
			for(int j=1; j<=m; j++){
				if(sum-i < 1 || sum-j < 1)
					continue;
				dp[sum][i][j] = max(dp[sum][i][j], dp[sum-1][i][j]);
				dp[sum][i][j] = max(dp[sum][i][j], dp[sum-1][i-1][j]);
				dp[sum][i][j] = max(dp[sum][i][j], dp[sum-1][i][j-1]);
				dp[sum][i][j] = max(dp[sum][i][j],  dp[sum-1][i-1][j-1]);
				dp[sum][i][j] += G[i][sum-i]+G[j][sum-j];
				if(i==j)
					dp[sum][i][j]-=G[i][sum-i];
			}
		}
	}
	cout << dp[m+n][m][m];
	return 0;
} 
