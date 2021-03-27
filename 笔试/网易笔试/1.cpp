
#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
const int maxn = 110;
int a[maxn][maxn];
int n;
int dist[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
bool vis[maxn][maxn];
vector<int> G[maxn * 2];
int bfs(int x, int y){
	memset(vis, 0, sizeof vis);
	vector<pi> q;
	q.push_back({x, y});
    for(int i = 0; i < n*2; i++){
        vector<pi> v;
        if(q.size() == 0) return 0;
        for(auto c : q){
            int x1 = c.first, y1 = c.second;
            // cout << x1 << " " <<y1 <<endl;
            for(int k = 0; k < 4; k++){
                int x_ = x1 + dist[k][0], y_ = y1 + dist[k][1];
                if(x_ < 0 || y_ < 0 || x_ >= n || y_ >= n) continue;
                if(vis[x_][y_]) continue;
                vis[x_][y_] = 1;
                if(a[x_][y_] == 1) return abs(x_-x)+abs(y_-y);

                v.push_back({x_, y_});
            }
        }
        q = v;
	}
	return 0;
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) cin >> a[i][j];
	}
	
	int maxx = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[j][i] == 1) continue;
			int d = bfs(j, i);
			// cout << i << " " << j << " " << d << endl;
			G[d].push_back(i);
			G[d].push_back(j);
			maxx = max(maxx, d);
		}
	}
	// cout << maxx << endl;
	if(maxx == 0){
		cout << 0 << endl;
	}
	else{

		for(auto c : G[maxx]) cout << c << " ";
		cout << endl;
	}
	return 0;
}