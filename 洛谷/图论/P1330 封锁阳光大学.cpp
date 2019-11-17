#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
int main(){
	int N, M;
	cin >>N >> M;
	vector<vector<int> > G(N+1);
	vector<bool> vis(N+1); 
	while(M--){
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	vector<int> color(N+1);
	map<int, int> col_num;
	col_num[1]=0; col_num[-1]=0;
	queue<int> q;
	int ans = 0;
	for (int i = 1; i <= N; i++){
		if(!vis[i]){
			vis[i]=1;
			color[i]=1;
			col_num[1]=1;            //col_num[1]++;???
			col_num[-1]=0;           //
			q.push(i);
			while (!q.empty()){
				int node = q.front();
				q.pop();
				for (int i=0; i<G[node].size(); i++){
					int node1=G[node][i];
					if(color[node] == color[node1]){
						cout << "Impossible" << endl;
						return 0;
					}
					if(!vis[node1]){
						vis[node1]=1;
						q.push(node1);
						color[node1]=-color[node];
						col_num[color[node1]]++;
					}
				}
			} 
			ans += min(col_num[-1], col_num[1]);            //
		}
	}
	//cout << min(col_num[-1], col_num[1]) << endl;
	cout << ans << endl;
	return 0;
}
