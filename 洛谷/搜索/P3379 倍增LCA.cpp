#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
vector<vector<int> > T(500005);
vector<int> deep(500005), lg(510006);
vector<vector<int> > dp(500005, vector<int> (50));
int n, m, s;
void dfs(int k, int f){
	deep[k] = deep[f]+1;
	dp[k][0] = f;
	for(int i=1; (1<<i)<=deep[k]; i++){  //(1<<i) 2的i次方 
		dp[k][i] = dp[dp[k][i-1]][i-1];  //画图验证 不会证明 
	}
	for(int i=0; i<T[k].size(); i++){
		int t = T[k][i];
		if(t != f)
			dfs(t, k);
	}
}
void lca(int x, int y){
	if(deep[x] < deep[y])
		swap(x, y);
	int d=deep[x] - deep[y], i=0; 
	for(; (1<<i)<=d; i++){
		if(d&(1<<i))
			x= dp[x][i];
	}
	if(x == y){
		cout <<x << endl;
		return;
	}
	for(int i=20; i>=0; i--){
		if(dp[x][i] != dp[y][i]){
			x=dp[x][i];
			y=dp[y][i];
		}
	}
	cout << dp[x][0] << endl;
} 
inline int read()
{
    int x=0; char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return x;
}
int main(){
	//ios::sync_with_stdio(0);
	cin >> n >> m >> s;
	for(int i=0; i<n-1; i++){
		int a, b;
		a=read();
		b=read();
		T[a].push_back(b);
		T[b].push_back(a);
	}
	dfs(s, 0);
	for(int i=1; i<=n; i++)
		lg[i] = lg[i-1]+(1<<lg[i-1]==i); 
	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		lca(x, y);
	}
	return 0;
} 
