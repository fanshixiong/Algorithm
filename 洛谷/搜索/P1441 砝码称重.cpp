#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int> weg(40);
int n, m, ans=0;
void returnMax(){
	vector<bool> dp(2550);
	int cnt=0, res=0;
	dp[0]=1;
	for(int i=0; i<n; i++){
		if(!weg[i])
			continue;
		for(int j=cnt; j>=0; j--){
			if(dp[j] && !dp[j+weg[i]]){
				dp[j+weg[i]]=1;
				res++;
			}
		}
		cnt+=weg[i];
	}
	ans=max(ans, res);
}
void dfs(int cur, int now){
	if(cur>n || now>m)
		return;
	if(cur==n && now==m){
		returnMax();	
		return;
	}
	dfs(cur+1, now);
	int tmp=weg[cur];
	weg[cur]=0;
	dfs(cur+1, now+1);
	weg[cur]=tmp;
}
int main(){
	//freopen("weight.in", "r", stdin);
	//freopen("weight.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> weg[i];
	dfs(0, 0);
	cout << ans << endl;
	return 0;
} 
