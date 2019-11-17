#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Knapsack (vector<int> &v, vector<int> &w, int c, int n, vector<vector<int> > &dp){
	int jmax = min(w[n]-1, c);

	for(int j = w[n]; j <= jmax; j++)
		dp[n][j] = v[n];
	for(int i = n-1 ; i > 1; i--){
		jmax = min(w[i]-1, c);
		for(int j = 0; j < jmax; j++) dp[i][j] = dp[i+1][j];
		for (int j = w[i]; j <= c; j++) dp[i][j] = max (dp[i+1][j], dp[i+1][j-w[i]]+v[i]);
	}
	dp[1][c]= dp[2][c];
	if (c >= w[1]) dp[1][c] = max(dp[1][c], dp[2][c-w[1]]+v[1]);
}
void TraceBack(vector<vector<int> > &dp, vector<int> &w, int c, int n, vector<int> &x){
	for(int i = 1; i < n; i++){
		if (dp[i][c] == dp[i+1][c]) x[i] = 0;
		else {
			x[i] =1;
			c -= w[i];
		}
	}
	x[n] = (dp[n][c]) ? 1 : 0;
}

int main(){
	int n = 6;
	vector<int> v(7);
	vector<int> w(7), x(7);
	int c = 12;
	vector<vector<int> > dp(7, vector<int> (13));
	v[1] = 8; w[1]=14;v[2] = 10; w[2]=6;v[3] = 3; w[3]=2;v[4] = 7; w[4]=5;v[5] = 2; w[5]=1;v[6] = 6; w[6]=1;
	Knapsack (v, w, c, n, dp);
	TraceBack (dp, w, c, n, x);
	for (int i = 1; i < 7; i++){

		cout << i << " " << x[i] << " " << endl;
	}
	system("pause");
	return 0;
}
