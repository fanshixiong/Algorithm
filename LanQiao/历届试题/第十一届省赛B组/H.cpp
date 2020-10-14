#include<bits/stdc++.h>

using namespace std;

#define ll unsigned long long

int dp[35][35];
int main(){
	int n, m;
	cin >> n >> m;
	
	memset(dp, 0, sizeof dp);
	dp[0][1] = 1;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if((i&1) || (j&1)) dp[i][j] += dp[i-1][j] + dp[i][j-1];
			else dp[i][j] = 0;
		}
	}
	
	cout << dp[n][m] << endl;
	return 0;
} 
