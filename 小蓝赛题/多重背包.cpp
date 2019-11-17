/*多重背包；循环超时，准换位01背包 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> value(10000);
vector<int> cost(10000);
int main(){
	int n, m;
	cin >> n >> m;
	vector<int> num(m+1); 
	for(int i = 1; i <= m; i++){
		cin >> cost[i] >> value[i] >> num[i];
	}
	vector<int> dp(n+1);
	int p = m;
	for(int i = 1; i <= p; i++){
		int o = num[i], j = 1;
		while (o > j){
			o -= j; m++;
			cost[m] = cost[i]*j;
			value[m] = value[i]*j;
			j <<= 1;
		}
		cost[i] = cost[i]*o;
		value[i] = value[i]*o;
	} 
	//for (int i = 1; i <= m; i++)
	//	cout << cost[i] << endl;
	for (int i = 1; i <= m; i++){
		for (int j = n; j >= cost[i]; j--){
			if (j >= cost[i])
				dp[j] = max(dp[j], dp[j-cost[i]]+value[i]);
		}
		/*
		for (int j = 1; j <= n; j++)
			cout << dp[j] << " ";
		cout << endl;
		*/
	}
	cout << dp[n] << endl;
	return 0;
}
