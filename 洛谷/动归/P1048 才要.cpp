#include<iostream>
#include<vector> 
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	int T, M;
	cin >>T >> M;
	vector<int> cost(M+1);
	vector<int> value(M+1);
	for(int i=1; i<M+1; i++)
		cin >> cost[i] >> value[i];
	vector<int> dp(T+1);
	/*
	for(int i=1; i<=M; i++){
		for(int j=T; j>0; j--){
			if(j >= cost[i])
			dp[j]=max(dp[j], dp[j-cost[i]]+value[i]);
		}
	}*/
	for(int i=1; i<=M; i++){
		for(int j=1; j<=T; j++){
			if(j >= cost[i])
				dp[j]=max(dp[j], dp[j-cost[i]]+value[i]);
		}
	}
	cout << dp[T] << endl;
	return 0;
}
