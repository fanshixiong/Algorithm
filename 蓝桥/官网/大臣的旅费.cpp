/*这题开二维数组在官网上是错误的：应该是图的存储空间过大，导致时间超限 
注意 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct path{
	int cost, to;
};
//vector<vector<int> > Path(10005, vector<int> (10005));
vector<vector<path> > Path(100010);
vector<bool> vis(10010);
int n;
int start = 0, maxcost = 0;
void dfs(int k, int c){
	if (c > maxcost){
		start = k;
		maxcost = c;
	}
	for (int i = 0; i < Path[k].size(); i++){
		if(!vis[Path[k][i].to] && Path[k][i].cost){
			vis[Path[k][i].to]=1;
			dfs(Path[k][i].to, Path[k][i].cost+c);
			vis[Path[k][i].to]=0;
		}
	}
}
int main(){
	cin >> n;
	for (int i = 0; i < n-1; i++){
		int x, y, z;
		cin >> x >> y >> z;
		path tp;
		tp.to=y; tp.cost=z;
		Path[x].push_back(tp);
		tp.to=x; tp.cost=z;
		Path[y].push_back(tp);
		//Path[x][y] = Path[y][x] = z;
	}
	vis[1]=1;
	dfs(1, 0);
	for (int i = 1; i <= n; i++){
		vis[i]=0;
	}
	maxcost=0;
	vis[start]=1;
	dfs(start, 0);
	cout << (11+10+maxcost)*maxcost/2;
	return 0; 
}
