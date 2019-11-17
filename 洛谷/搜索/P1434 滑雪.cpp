#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
	int x,y;
	int high, value;
};
bool cmp(Node &a, Node &b){
	return a.high < b.high;
}
vector<Node> grids;
int dist[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int res = 0;
int N, M;
int main(){
 	cin >> N >> M ;
 	vector<vector<int> > gg(N, vector<int>(M));
 	vector<vector<int> > ans(N, vector<int>(M, 1));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> gg[i][j];
			Node tmp;
			tmp.x = i; tmp.y=j; tmp.high=gg[i][j]; tmp.value=1;
			grids.push_back(tmp); 
		} 
	}
	sort(grids.begin(), grids.end(), cmp);
	int k = 0;
	while (k<grids.size()){
		int x1=grids[k].x;
		int y1=grids[k].y;
		for (int i = 0; i < 4; i++){
			int x0 = x1+dist[i][0];
			int y0 = y1+dist[i][1];
			if (x0>=0 && x0<N && y0>=0 && y0<M && gg[x0][y0] < grids[k].high)
				ans[x1][y1] = max(ans[x1][y1], ans[x0][y0]+1);
		}
		res = max(res, ans[x1][y1]);
		k++;
	}
	cout << res << endl;
 	return 0;
}
