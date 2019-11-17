#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
using namespace std;
int main(){
	int V; cin >> V;
	int n; cin >> n;
	vector<int> cap(n+1);
	for(int i=1; i<=n; i++)
		cin >> cap[i];
	vector<int> dp(V+1);
	for(int i=1; i<=n; i++){
		for(int j=V; j>=1; j--){
			if(j>=cap[i])
				dp[j]=max(dp[j], dp[j-cap[i]]+cap[i]);
		}
	}
	cout << V-dp[V] << endl;
	return 0;
} 
