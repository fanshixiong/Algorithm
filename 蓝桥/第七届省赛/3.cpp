#include<iostream>
#include <vector>
using namespace std;
int dist[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
vector<int> num(9, 0);
vector<vector<int> > graph(3, vector<int>(4, -5));
int res = 0;
bool judge(int x, int y, int k){
	int d[4][2] = {0, -1,  -1, 0,  -1, -1,  -1, 1};
	for (int i = 0; i < 4; i++){
		int x1 = x+d[i][0];
		int y1 = y+d[i][1];
		if (x1 >= 0 && y1 >= 0 && x1<=2 && y1 <= 2)
			if ( k == graph[x1][y1]+1 || k == graph[x1][y1]-1)
				return false;
	}
	return true;
}
void dfs(int x, int y){
	if (x == 2 && y == 3){
		res++;
		return;
	}
	if (y > 3)
		dfs(x+1, 0);
	else{
		for (int i = 0; i < 10; i++){	
			if (judge(x, y, i)&&!num[i]){
				num[i]++;
				graph[x][y]=i;
				dfs(x, y+1);
				graph[x][y]=-5;
				num[i]--;
			}
		}
	}
}
int main(){
	graph[0][0] = 18;
	graph[2][3] = 15;
	dfs(0, 1);
	cout << res << endl;
	return 0;
} 
