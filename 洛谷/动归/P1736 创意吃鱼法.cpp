#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int dp[2501][2501], G[2501][2501], row[2501][2501], col[2501][2501];
int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int ans=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++)
			cin >> G[i][j];
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(!G[i][j]){
				row[i][j]=row[i-1][j]+1;
				col[i][j]=col[i][j-1]+1;
			}
			
			if(G[i][j]==1){
				dp[i][j]=min(dp[i-1][j-1], min(row[i-1][j], col[i][j-1]))+1;
			}
			ans=max(ans, dp[i][j]);
		}
	
		for(int j=1; j<=m; j++)
			col[i][j]=0;
		for(int j=m; j>=1; j--){
			if(!G[i][j]){
				col[i][j]=col[i][j+1]+1;	
			}
			if(G[i][j]==1){
				dp[i][j]=max(dp[i][j], min(dp[i-1][j+1], min(row[i-1][j], col[i][j+1]))+1);
			}
			ans=max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
} 
