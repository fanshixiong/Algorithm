#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <map>
using namespace std;
void MinEditDist(){
	//≥ı ºªØ 
	int A[5][5]={
		{5, -1, -2, -1, -3},
		{-1, 5, -3, -2, -4},
		{-2, -3, 5, -2, -2},
		{-1, -2, -2, 5, -1},
		{-3, -4, -2, -1, 0}
	};
	map<char, int> mmp;
	mmp['A']=0; mmp['C']=1; mmp['G']=2; mmp['T']=3; mmp['-']=4;
	int m, n; cin >> m;
	string S1,S2; cin >> S1;
	cin >> n >> S2;
	vector<vector<int> > dp(m+1, vector<int>(n+1, -0x3f3f33ff));
	dp[0][0]=0;
	//Algorithm:
	for(int i=1; i<=m; i++)
		dp[i][0]=dp[i-1][0]+A[mmp[S1[i-1]]][4];
	for(int j=1; j<=n; j++){
		dp[0][j]=dp[0][j-1]+A[4][mmp[S2[j-1]]];
	}
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			dp[i][j]=max(dp[i][j], dp[i-1][j]+A[mmp[S1[i-1]]][4]);  //delete
			dp[i][j]=max(dp[i][j], dp[i][j-1]+A[4][mmp[S2[j-1]]]);  //insert
			dp[i][j]=max(dp[i][j], dp[i-1][j-1]+A[mmp[S1[i-1]]][mmp[S2[j-1]]]);  //substitution
		}
	}
	cout << dp[m][n] << endl;
} 
int main(){
	MinEditDist();
	return 0;
}
