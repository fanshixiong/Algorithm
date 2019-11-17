#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
struct Horse{
	int x, y;
	int step;
};
int dist[8][2] = {1, 2, 1, -2, 2, 1, 2, -1, -1, 2, -1, -2, -2, 1, -2, -1};
int main(){
	int n, m, x0, y0;
	cin >> n >> m >> x0 >> y0;
	vector<vector<int> > horse(n, vector<int> (m));
	vector<vector<bool> > vis(n, vector<bool> (m));
	queue<Horse> hor;
	Horse tmp; tmp.x=x0-1; tmp.y=y0-1; tmp.step=0;
	vis[tmp.x][tmp.y]=1;
	hor.push(tmp);
	while(!hor.empty()){
		tmp = hor.front();
		hor.pop();
	//	cout << tmp.x << " " << tmp.y << " " << tmp.step << endl;
		for (int i = 0; i < 8; i++){
			int x1 = tmp.x + dist[i][0];
			int y1 = tmp.y + dist[i][1];
			if((x1 >= 0 && y1 >= 0 && x1 < n && y1 < m) && !vis[x1][y1]){
				Horse tp; tp.x=x1; tp.y=y1; tp.step = tmp.step+1;
				horse[x1][y1]=tp.step;
				vis[x1][y1]=1;
				hor.push(tp);
			}
		}
	}
	for (int i = 0; i < n; i ++){
		for (int j = 0; j < m; j++){
			if(horse[i][j]){
				printf("%-5d", horse[i][j]);
			}
			else if(i == x0-1 && j == y0-1)
				printf("%-5d", 0);
			else
				printf("%-5d", -1);
		}
		cout << endl;
	}
	return 0;
} 
