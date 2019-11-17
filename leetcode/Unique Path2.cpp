#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	vector<vector<int> > dp(m+1, vector<int> (n+1));
	if (grid[0][0] == 0) dp[0][1] = 1;
	for (int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			if(!dp[i][j])
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
	cout << dp[m-1][n-1] << endl;
	return 0;
}
