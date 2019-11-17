#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void TraceBack(int n, vector<int> &w, vector<int> &v, vector<vector<int> > &dp, vector<int> &head, vector<bool> &x){
	int j = dp[head[0]-1][0], m = dp[head[0]-1][1];
	for (int i = 1; i <= n; i++){
		x[i] = 0;
		for (int k = head[i+1]; k <= head[i]-1; k++){
			if (dp[k][0] +w[i] == j && dp[k][1] + v[i] == m){
				x[i] =1; j = dp[k][0]; m = dp[k][1]; break;
			}
		}
	}
}
int Knapsack (vector<int> &v, vector<int> &w, int c, int n, vector<vector<int> > &dp, vector<bool> &x){
	vector<int> head(n+2);
	head[n+1] = dp[0][0] = dp[0][1] = 0;
	int left = 0, right = 0, next = 1;
	for (int i = n; i >= 1; i--){
		int k = left;
		for (int j = left; j <= right; j++){
			if (dp[j][0] + w[i] > c) break;
			int y = dp[j][0] + w[i], m = dp[j][1] + v[i];
			while (k <= right && dp[k][0] < y){
				dp[next][0] = dp[k][0];
				dp[next++][1] = dp[k++][1];
			}
			if (k <= right && dp[k][0] == y){
				if (m < dp[k][1])
					m = dp[k][1];
				k++;
			}
			if (m > dp[next-1][1]){
				dp[next][0] = y;
				dp[next++][1] = m;
			}
			while (k <= right && dp[k][1] <= dp[next-1][1]) k++;
		}
			while (k <= right){
				dp[next][0] = dp[k][0];
				dp[next++][1] = dp[k++][1];
			}
			left = right+1; right = next-1;head[n-1] = next;
	}
	TraceBack (n, w, v, dp, head, x);
	return dp[next-1][1];
	
}
int main(){
	int n = 6;
	vector<int> v(7);
	vector<int> w(7);
	vector<int> head(7);
	vector<bool> x(7);
	int c = 12;
	vector<vector<int> > dp(7, vector<int> (13));
	v[1] = 8; w[1]=14;v[2] = 10; w[2]=6;v[3] = 3; w[3]=2;v[4] = 7; w[4]=5;v[5] = 2; w[5]=1;v[6] = 6; w[6]=1;
	Knapsack (v, w, c, n, dp, x);
	for (int i = 1; i < 7; i++){

		cout << i << " " << x[i] << " " << endl;
	}
	system("pause");
	return 0;
}
