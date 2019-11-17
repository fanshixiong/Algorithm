#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int m, n;
vector<int> val(100000), num(10);
int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> val[i];
	for(int i=0; i<m; i++){
		int x; cin >> x;
		num[x]++;
	}
	int dp[41][41][41][41]={0};
	dp[0][0][0][0] = val[0];
	for(int i=0; i<=num[1]; i++){
		for(int j=0; j<=num[2]; j++){
			for(int p=0; p<=num[3]; p++){
				for(int k=0; k<=num[4]; k++){
					int x = i*1+j*2+k*4+p*3;
					if(i) dp[i][j][p][k] = max(dp[i][j][p][k], dp[i-1][j][p][k]+val[x]);
					if(j) dp[i][j][p][k] = max(dp[i][j][p][k], dp[i][j-1][p][k]+val[x]);
					if(p) dp[i][j][p][k] = max(dp[i][j][p][k], dp[i][j][p-1][k]+val[x]);
					if(k) dp[i][j][p][k] = max(dp[i][j][p][k], dp[i][j][p][k-1]+val[x]);
				}
			}
		}
	} 
	cout << dp[num[1]][num[2]][num[3]][num[4]];
	return 0;
} 
