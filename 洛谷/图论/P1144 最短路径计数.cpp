#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
class Roads{
	int N;
	vector<vector<int> > G; 
	vector<int> dist;
	vector<int> ans;
public:
	Roads(){
		int M;
		cin >> N >> M;
		G.resize(N+1);
		dist.resize(N+1);
		ans.resize(N+1);
		for (int i = 1; i<=M; i++){
			int x, y; cin >> x >> y;
			if(x==y) continue;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		for (int i = 1; i <= N; i++){
			dist[i]=0x3f3f3f3f;
		}
	}
	void spfa(){
		vector<bool> vis(N+1);
		queue<int> q;
		q.push(1); vis[1]=1; dist[1]=0; ans[1]=1;
		while(!q.empty()){
			int tmp = q.front();
			q.pop();
			vis[tmp]=0;
			for (int i=G[tmp].size()-1; i>=0; i--){
				int t=G[tmp][i];
				if(dist[t]>dist[tmp]+1){
					dist[t]=dist[tmp]+1;
					ans[t]=ans[tmp];
					if(!vis[t]){
						q.push(t);
						vis[t]=1;
					}
				}
				else if(dist[t]==dist[tmp]+1){
					ans[t]+=ans[tmp];
					ans[t]%=100003;
				}
			}
		}
		for (int i = 1; i<=N; i++)
			cout << ans[i]<<endl;
	}
};
int main(){
	Roads test;
	test.spfa();
	return 0;
} 
