/*
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int num[205][206];
bool vis[205][205];
int dist[2][2] = {0, 1, 0, -1};
void dfs(int x0, int y0, int count, int n, int d){
	if(x0+1 >= n && y0+1 >= n) return;
	int x = x0 + dist[d][0];
	int y = y0 + dist[d][1];
	//if(x == 1 && y == 2) cout << vis[x][y] << num[x][y] << endl;
	if(x>=0 && y>=0 && x<n && y<n && !vis[x][y]){
		num[x][y] = (++(count) % 26);
		vis[x][y] = 1;
		dfs(x, y, count, n, d);
	}
	else if(x<0 || x>=n || y<0 || y>=n || vis[x][y]){
		//d = (d+1) %4;
		if(d==0) d=1, y=y0+1;
		else if(d==1) d=0, y=y0-1;
		x = x0+1;
		dfs(x, y, count, n, d);
	}
}
void solve(int n){
	//memset(num, 0, n*n);
	memset(vis, 0, sizeof(vis));
	//cout << num[1][2] << vis[1][2] << endl;
	vis[0][0] = 1;
	num[0][0] = 0;
	dfs(0, 0, 0, n, 0);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << (char)(num[i][j] + 'a');
		}
		cout << endl;
	}
}
int main(){
	int n;
	while(scanf("%d", &n)){
		solve((2*n+1));
	}
	return 0;
} */
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int num[205][206];
void solve(int n){
	int count=0;
	int h=0, len=2*n+1;
	for(int i=0; i<n; i++){
		for(int j=0; j<len; j++)
			num[h][j] = ((count) % 26), count++;
		h++;
		for(int j=len-1; j>=0; j--)
			num[h][j] = ((count) % 26), count++;
		h++;
	}
	for(int j=0; j<len; j++){
		num[len-1][j] = ((count) % 26), count++;
	}
	for(int i=0; i<len; i++){
		for(int j=0; j<len; j++){
			cout << (char)(num[i][j] + 'a');
		}
		cout << endl;
	}
}
int main(){
	int n;
	while(scanf("%d", &n) !=){
		solve(n);
	}
	return 0;
} 
