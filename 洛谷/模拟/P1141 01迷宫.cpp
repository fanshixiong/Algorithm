/*
并查集联通 
*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
int dist[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
char maze[1005][1005];
int vis[1005][1005];
int ans[100005];
int n;
void dfs(int x, int y, int sign){
	//cout << sign<<"  " << ans[sign]<<endl;
	for(int i = 0; i < 4; i++){
		int x1=x+dist[i][0];
		int y1=y+dist[i][1];
		if(x1>0&&y1>0&&x1<=n&&y1<=n&&vis[x1][y1]!=sign&&((maze[x1][y1]=='0'&&maze[x][y]=='1')||(maze[x1][y1]=='1'&&maze[x][y]=='0'))){
			ans[sign]++;
			vis[x1][y1]=sign;
			dfs(x1, y1, sign);
		}
	}
} 
int main(){
	int  m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> maze[i][j];
		}
	}
	memset(vis, -1, sizeof(vis));
	memset(ans, 0, sizeof(ans));
	while(m--){
		int x0, y0;
		cin >> x0 >> y0;
		if(vis[x0][y0]==-1){
			vis[x0][y0]=m;
			dfs(x0, y0, m);
			cout <<ans[m]+1 << endl;
		}
		else
			cout <<ans[vis[x0][y0]]+1 << endl;
	}
	return 0;
} 

/*
#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
struct Maze{
	int x, y;
};
int dist[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<char> > maze(n+1, vector<char>(m+1));
	for(int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> maze[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
	while(m--){
		int x0, y0;
		cin >> x0 >> y0;
		vector<vector<bool> > vis(n+1, vector<bool>(m+1));
		queue<Maze> maz;
		Maze tmp; tmp.x = x0; tmp.y = y0;
		maz.push(tmp);
		vis[x0][y0]=1;
		int ans = 1;
		while(!maz.empty()){
			tmp = maz.front();
			maz.pop();
			for (int i = 0; i < 4; i++){
				int x1 = tmp.x+dist[i][0];
				int y1 = tmp.y+dist[i][1];
				if(x1>0&&y1>0&&x1<=n&&y1<=n&&!vis[x1][y1]&&((maze[x1][y1]=='0'&&maze[tmp.x][tmp.y]=='1')||(maze[x1][y1]=='1'&&maze[tmp.x][tmp.y]=='0'))){
					ans++;
					vis[x1][y1]=1;
					Maze tp;
					tp.x = x1; tp.y = y1;
					maz.push(tp);
				}
			}
		}
		cout << ans << endl; 
	}
	return 0;
} */
