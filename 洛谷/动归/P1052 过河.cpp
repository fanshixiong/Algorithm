/*
***@author :luogu yzpyzp
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int L, S, T, M;
	cin >> L >>S >>T>>M;
	vector<int> dp(5000, 0x3f3f3f3f), stone(M+1);
	for(int i=1; i<=M; i++){
		cin >> stone[i];
	}
	sort(stone.begin(), stone.end());
	if(S==T){
		int cnt=0;
		for(int i=1; i<=M; i++)
			if(stone[i]%S==0)
				cnt++;
		cout << cnt << endl;
		return 0;
	}
	int base=S*T;
	vector<int> dis(9000), vis(9000);
	for(int i=1; i<=M; i++){
		int d=stone[i]-stone[i-1];
		if(d>=base)
			d=base;
		dis[i]=dis[i-1]+d;
		vis[dis[i]]=1;
	}
	L=dis[M]+base;
	dp[0]=0; 
	for(int i=1; i<=L; i++){
		for(int j=S; j<=T; j++){
			if(i-j>=0){
				if(vis[i]) dp[i]=min(dp[i-j]+1, dp[i]);
				else dp[i]=min(dp[i-j], dp[i]);		
			}
		}
	}
	int ans=0x3f3f3f3f;
	for(int i=dis[M]; i<=L; i++){
		ans=min(ans, dp[i]);
	}
	cout << ans << endl;
} 
