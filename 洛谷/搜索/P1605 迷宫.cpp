 #include <iostream>
 #include <vector>
 using namespace std;
 int N, M, T;
 int SX, SY, FX, FY;
 vector<vector<int> > grids;
 vector<vector<bool> > vis;
 int dist[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
 int res = 0;
 void dfs(int x, int y){
 	//cout << x << " " << y<< endl;
	if (x == FX && y == FY){
 		res++;
 		return;
	 }
	 for (int i = 0; i < 4; i++){
	 	int x1 = x+dist[i][0];
	 	int y1 = y+dist[i][1];
	 	if (x1>0&&x1<=N&&y1>0&&y1<=M&&!vis[x1][y1]&&!grids[x1][y1]){
	 		//cout << x1 << " " << y1<< " " << vis[x1][y1] << " " << grids[x1][y1] << endl;
	 		vis[x1][y1]=1;
	 		dfs(x1, y1);
			vis[x1][y1]=0;	
		}
	 }
 }
 int main(){
 	cin >> N >> M >> T;
 	vector<vector<int> > dp(N+1, vector<int> (N+1));
 	cin >> SX >> SY >> FX >> FY;
 	grids.resize(N+1);
 	vis.resize(N+1);
	for (int i = 0; i < N+1; i++){
		grids[i].resize(M+1);
		vis[i].resize(M+1);
	}
	while (T--){
		int x, y;
		cin >> x >> y;
		grids[x][y] = 1;
	}
	//cout << vis[1][4] <<endl;
	vis[SX][SY]=1;
	dfs(SX, SY);
	cout << res << endl;
 	return 0;
 }
