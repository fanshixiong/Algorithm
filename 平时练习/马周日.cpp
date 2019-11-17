//            马周日问题：
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std; 
#define INF 0x3f3f3f3f
int way[8][2] = {
	2, 1,
	2, -1,
	-2, 1,
	-2, -1,
	1, 2,
	1, -2,
	-1, 2,
	-1, -2,
};
class Horse{
	int m, n;       //棋盘大小 
	int res;
	int k, w;       //初始位置 
	int total;      //总共遍历的棋盘方格数
	vector<vector<bool> > visited;
	public:
		Horse (int a, int b, int x, int y){
			m = a; n = b;
			k = x; w = y;
			res = 0; total = 1;
			visited.resize(m);
			for(int i = 0; i < m; i++){
				visited[i].resize (n);
				for(int j = 0; j < n; j++)
					visited[i][j] = false;
			}
			visited[x][y] = true;
		}
		bool is_legal (int x, int y){
			if (x < 0 || y < 0 || x >= m || y >= n || visited[x][y])
				return false;
			return true;
		}
		bool is_ok (){
			if(total == m*n)
				return true;
			return false;
		}
		void horse(int x, int y){
				for (int i = 0; i < 8; i++){
					if (is_legal(x+way[i][0], y+way[i][1])){
						visited[x+way[i][0]][y+way[i][1]] = true;
						total++;
						if (is_ok())
							res++;
						horse(x+way[i][0], y+way[i][1]);
						total--;
						visited[x+way[i][0]][y+way[i][1]] = false;
					}
				}
			return;
		}
		int GetResult(){
			
			horse(0, 0);
			cout << res;
			return res;
		}
};
int main(){
//	freopen ("666.txt", "r", stdin);
//	std::ios::sync_with_stdio(false);
//	freopen ("666.txt", "w", stdout);
	Horse test(4, 5, 0, 0);
	test.GetResult();
	system("pause");
	return 0;
}
