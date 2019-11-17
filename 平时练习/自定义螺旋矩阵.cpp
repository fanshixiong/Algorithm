// ÂÝÐý¾ØÕó 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int dis[4][2] = {{1, 0}, {-1, 1}, {0, 1}, {1, -1}};
void dfs(int x0, int y0, int d, int count, vector<vector<int> > &a, vector<vector<bool> > &vis){
	if (x0+1 >= n && y0+1 >= n) return;
	int x = x0 + dis[d][0];
	int y = y0 + dis[d][1];
	if (x >= 0 && y >= 0 && x < n && y < n && !vis[x][y]){
		a[x][y] = ++count;
		vis[x][y] = 1;
		if (d == 0) d = 1;
		if (d == 2) d = 3;
		dfs(x, y, d, count, a, vis);
	}
	else if (x<0||x>=n||y<0||y>=n||vis[x][y]){
		d = (d+1) % 4;
		dfs(x0, y0, d, count, a, vis);
	}
}
int main(){
	cin >> n;
	vector<vector<int> > a(n, vector<int>(n));
	vector<vector<bool> > vis(n, vector<bool>(n));
	a[0][0] = 1;
	vis[0][0] = 1;
	if (n == 1);
	else if (n == 2){
		a[0][1] = 2; a[1][0] = 4;
		a[1][1] = 3;
	}
	else
		dfs(0, 0, 0, 1, a, vis) ;
	for(int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "\t";
		cout << endl;	
	}
	system("PAUSE");
	return 0;
}
