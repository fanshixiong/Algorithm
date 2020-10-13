#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e3+10;


int dist[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int vis[maxn][maxn];
string maps[maxn];
int n, ans = 0;

void bfs(int x, int y){
	queue<pair<int, int> > q;
	q.push({x, y});
	vis[x][y] = 1;
	
	int cnt_l = 1, cnt_s = 0;
	if((x>0 && maps[x-1][y]=='.') || (y>0 && maps[x][y-1]=='.') || (x<n-1 && maps[x+1][y]=='.') || (y<n-1 && maps[x][y+1]=='.')) { 
		cnt_s++;
		maps[x][y] = '*';
	}
	while(!q.empty()){
		pair<int, int> u = q.front(); q.pop();
		
		int x1 = u.first, y1 = u.second;
		
		for(int i = 0; i < 4; i++){
			int _x = x1 + dist[i][0];
			int _y = y1 + dist[i][1];
			
			if(_x < 0 || _y < 0 || _x >= n || _y >= n) continue;
			
			if(vis[_x][_y] || maps[_x][_y] == '.') continue;
			
			cnt_l ++;
			vis[_x][_y] = 1;
			q.push({_x, _y});
			
			if((_x>0 && maps[_x-1][_y]=='.') || (_y>0 && maps[_x][_y-1]=='.') || (_x<n-1 && maps[_x+1][_y]=='.') || (_y<n-1 && maps[_x][_y+1]=='.')) { 
				cnt_s++;
				maps[_x][_y] = '*';
			}
		}
	}
	if(cnt_l == cnt_s) ans++;
}

int main(){
	memset(vis, 0, sizeof vis);
	freopen("7.txt", "r", stdin);
	cin >> n; 
	// string s;
	// int c = 0;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		maps[i] = s;
	}
	// while(cin >> s) maps[c++] = s;
	
	for(int i = 0; i < n; i++) cout << maps[i] << endl;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!vis[i][j] && maps[i][j] == '#') bfs(i, j);
		}
	}
	
	cout << endl;
	for(int i = 0; i < n; i++) cout << maps[i] << endl;
	
	cout << ans << endl;
	return 0;
}
