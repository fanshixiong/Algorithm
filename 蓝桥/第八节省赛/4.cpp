#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <deque>
#include <cmath>
using namespace std;
int ans = 0;
vector<vector<int> > graph(10, vector<int> (10));
int dist[4][2] = {0, 1, 0, -1, 1, 0, 1, -1};
void dfs(int x, int y){
	if (x == 0 || y == 0 ||  x == 6 || y == 6){
		ans++;
		return;
	}
	else{
		for (int i = 0; i < 4; i++){
			int x1 = x + dist[i][0];
			int y1 = y + dist[i][1];
			if (graph[x1][y1] == 0){
				graph[x1][y1] = 1;
				graph[6-x1][6-y1] = 1;
				dfs(x1, y1);
				graph[x1][y1] = 0;
				graph[6-x1][6-y1] = 0;
			}
		}
	}
}
int main(){
	graph[3][3] = 1;
	dfs(3, 3);
	cout << ans/4 << endl;
	return 0;
}
