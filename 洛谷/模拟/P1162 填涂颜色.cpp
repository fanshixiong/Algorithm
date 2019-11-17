#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dist[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
struct Pos{
	int x, y;
};
int main(){
	int n; cin >> n;
	vector<vector<int> > grids(n+2, vector<int> (n+2));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> grids[i][j];
		}
	}
	grids[0][0] = 1;
	queue<Pos> q;
	Pos pos; pos.x = 0; pos.y = 0;
	q.push(pos);
	while(!q.empty()){
		pos = q.front();
		q.pop();
		for (int i = 0; i < 4; i++){
			int x1 = pos.x+dist[i][0];
			int y1 = pos.y+dist[i][1];
			if (x1>=0 && x1<=n+1 && y1>=0 && y1<=n+1 && grids[x1][y1]==0){
				Pos tp; tp.x = x1; tp.y = y1;
				grids[x1][y1] = 3;
				q.push(tp); 
			}
		}
	} 
	for (int i = 1; i < n+1; i++){
		for (int j = 1; j < n+1; j++){
			if (grids[i][j] == 1)
				cout << 1 << " ";
			else if(grids[i][j] == 0)
				cout << 2 << " ";
			else
				cout << 0 << " ";
		}
		cout << endl;
	}
	return 0;
} 
