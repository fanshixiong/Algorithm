#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
int n, k;
vector<vector<int> > dp(100005, vector<int>(2));
int main(){
	cin >> n >> k;
	
	for(int i=0; i<n; i++){
		int x; cin >> x;
		dp[x][1]++;
	}
	long long ans=0;
	if(k==0){
		for(int i=0; i<100001; i++){
			if(dp[i][1])
				ans++;
		}
	}
	else{
		vector<bool> vis(100005);
		for(int i=100001; i>=0; i--){
			if(!vis[i] && dp[i][1]){
				vis[i]=1;
				int tmp=i, j=i, tp=0;
				for(; j>=0; j-=k){
					if(!vis[j]){
						vis[j]=1;
						dp[j][0]+=max(dp[tmp][0], dp[tmp][1]);
						dp[j][1]+=dp[tmp][0];
						tmp=j;
						tp=max(dp[j][0], dp[j][1]);
					}
				}
				ans+=tp;
			}
		}
	}
	cout << ans <<endl;
	return 0;
} 
