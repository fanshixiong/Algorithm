#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
long long dp[110][105][105]; 
inline long long C(long long x){
    return ((x*(x-1))/2)%9999973;
}
int main(){
	int m, n;
	cin >> m >> n;
	dp[0][0][0]=1;
	for(int k=1; k<=m; k++){
		for(int i=0; i<=n; i++){
			for(int j=0; j<=n-i; j++){
				dp[k][i][j]=dp[k-1][i][j];
				if(j>=1) dp[k][i][j] += dp[k-1][i+1][j-1]*(i+1);
				if(i>=1) dp[k][i][j] += dp[k-1][i-1][j]*(n-(i-1)-j);
				if(j>=2) dp[k][i][j] += dp[k-1][i+2][j-2]*(((i+2)*(i+1))/2);
				if(j>=1) dp[k][i][j] += dp[k-1][i][j-1]*(n-i-j+1)*i;
				if(i>=2) dp[k][i][j] += dp[k-1][i-2][j]*C(n-i-j+2);
				dp[k][i][j]%=9999973;
			}
		}
	}
	long long ans=0;
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			ans = (ans+dp[m][i][j])%9999973;
		}
	}
	ans %= 9999973;
	//cout << ans <<endl;
	printf("%lld", ans);
	return 0;
} 
