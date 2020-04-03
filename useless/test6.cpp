/*小蓝赛  种草 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
int d[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
class Farm{
	int N;
	vector<vector<int> > graph;               //图 
	vector<int> data;                        //每个颜色的数据 
public:
	Farm(){
		cin >> N;
		data.resize(N*N); 
		graph.resize(N);
		for (int i = 0; i < N; i++){
			graph[i].resize(N);
			for(int j = 0; j < N; j++)
				cin >> graph[i][j]; 
		}
	}
	bool is_ok(int x, int y){
		return x>=0 && x < N && y >= 0 && y < N;
	} 
	int dfs(int x0, int y0, int color){
		int res = 0;
		graph[x0][y0] = color;
		for (int k = 0; k < 4; k++){
			int x = x0 + d[k][0];
			int y = y0 + d[k][1];
			if (is_ok(x, y) && graph[x][y] == 1){
				res += dfs(x, y, color);
			}
		}
		return res+1;
	}
	int returnmaxarea(){
		int res = 0;
		int color = 2;
		for(int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (graph[i][j] == 1){
					data[color] = dfs(i, j, color);
					res = max(res, data[color]);
					color++;
				}
			}
		}
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (graph[i][j] == 0){
					int res_cur = 1;
					set<int> vis;                            //判重        //不能写为全局  因为每一次都要比较 
					for (int k = 0; k < 4; k++){
						int x = i + d[k][0];
						int y = j + d[k][1];
						if (is_ok(x, y) && graph[x][y] > 1 && !vis.count(graph[x][y])){
							vis.insert(graph[x][y]);
							res_cur += data[graph[x][y]];
						}
					}
					res = max(res, res_cur);
				}
			}
		} 
		return res;
	}
};
int main(){
	Farm test;
	cout << test.returnmaxarea() << endl;
	return 0;
}
