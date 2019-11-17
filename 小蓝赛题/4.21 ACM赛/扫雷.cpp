#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int dp[10005][2][2];
int main(){
	int n; cin >> n;
	int num[n+1];
	for(int i=1; i<=n; i++)
		cin >> num[i];
	if(num[1]==1)
		dp[1][1][0]=dp[1][0][1]=1;
	else if(num[1]==2)
		dp[1][1][1]=1;
	else 
		dp[1][0][0]=1;
	for(int i=2; i<n; i++){
		if(num[i]==0){
			dp[i][0][0]=dp[i-1][0][0];
		}
		else if(num[i]==1){
			dp[i][1][0]=dp[i-1][0][1];
			dp[i][0][1]=dp[i-1][0][0];
			dp[i][0][0]=dp[i-1][1][0];
		}
		else if(num[i]==2){
			dp[i][1][1]=dp[i-1][0][1];
			dp[i][0][1]=dp[i-1][1][0];
			dp[i][1][0]=dp[i-1][1][1];
		}
		else
			dp[i][1][1]=dp[i-1][1][1];
	}
	if (num[n]==2){
		cout << dp[n-1][1][1] << endl;
	}
	else if(num[n]==0)
		cout << dp[n-1][0][0] << endl;
	else 
		cout << dp[n-1][0][1] + dp[n-1][1][0] << endl;
	return 0;
}
