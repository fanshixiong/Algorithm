#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;
int n, q;
int R[maxn], C[maxn];
bool maze[maxn][maxn];
bool vis[maxn][maxn];
int d[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
bool ans=0;

void dfs(int a, int b, int dx, int dy){
	//cout << a << " " <<b << endl;
	if(a==dx && b==dy){
		ans=1;
		return;
	}
	for(int i=0; i<4; i++){
		int x=a+d[i][0];
		int y=b+d[i][1];
		if(x>=0 && x<n && y>=0 && y<n){
			if(maze[x][y] && !vis[x][y]){
				vis[x][y]=1;
				dfs(x, y, dx, dy);
				vis[x][y]=0;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin >> n >> q;
	for(int i=0; i<n; i++)
		cin >> R[i];
	for(int i=0; i<n; i++)
		cin >> C[i];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if((R[i]+C[j])%2)
				maze[i][j]=0;
			else
				maze[i][j]=1;
		}
	}
	while(q--){
		ans=0;
		memset(vis, 0, sizeof(vis));
		int ra, ca, rb, cb;
		cin >> ra >> ca >> rb >> cb;
		vis[ra-1][ca-1]=1;
		dfs(ra-1, ca-1, rb-1, cb-1);
		if(ans)
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
	return 0;
}
