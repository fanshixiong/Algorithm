#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	int m, n;
	cin >> m >> n;
	vector<vector<int> > dp(m+1, vector<int>(n+1));
	int ans=0;
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			cin >> dp[i][j];
			if(dp[i][j]==1){
				dp[i][j]=min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j])+1;
			}
			ans=max(ans, dp[i][j]);
		}
	} 
	cout <<ans<<endl;
	return 0;
} 
