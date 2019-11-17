#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	vector<int> value(m+1);
	vector<int> cost(m+1);
	for(int i = 1; i <= m; i++){
		cin >> cost[i] >> value[i];
	}
	vector<int> dp(n+1);
	for (int i = 1; i <= m; i++){
		for (int j = n; j >= 1; j--){
			if (j >= cost[i])
				dp[j] = max(dp[j], dp[j-cost[i]]+value[i]);
		}
	}
	/*
	for (int i = 1; i <= m; i++){
		for (int j =1; j <= n; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}*/
	cout << dp[n] << endl;
	return 0;
}
