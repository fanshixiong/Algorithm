#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
vector<int> low(100005), dfn(100005), color(100006), num(100005);
int m, n, cnt=0, col=0;
stack<int> s;
vector<bool> vis(100005);
vector<vector<int> > G(100006), G1(100005), G2(100006);
vector<int> grass1(100005, -1), grass2(100005, -1);
void tarjan(int k){
	dfn[k] = low[k] = ++cnt;
	vis[k]=1;
	s.push(k);
	for(int i=0; i<G[k].size(); i++){
		int t=G[k][i];
		if(!dfn[t]){
			tarjan(t);
			low[k] = min(low[k], low[t]);
		}
		else if(vis[t]){
			low[k] = min(low[k], low[t]);
		}
	}
	if(dfn[k] == low[k]){
		color[k] = ++col;
		vis[k] = 0;
		num[col]++;
		while(s.top() != k){
			color[s.top()] = col;
			num[col]++;
			vis[s.top()]=0;
			s.pop();
		}
		s.pop();
	}
}
void spfa1(int k){
	grass1[k]=num[k];
	queue<int> q;
	q.push(k);
	for(int i=0; i<=n; i++)
		vis[i]=0;
	vis[k]=1;
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		for(int i=0; i<G1[tmp].size(); i++){
			int t=G1[tmp][i];
			if(grass1[t] < grass1[tmp] + num[t]){
				grass1[t] = grass1[tmp] + num[t];
				if(!vis[t]){
					q.push(t);
					vis[t]=1;
				}
			}
		}
		vis[tmp]=0;
	}
}
void spfa2(int k){
	grass2[k] = num[k];
	queue<int> q;
	q.push(k);
	for(int i=0; i<=n; i++)	
		vis[k] = 0;
	vis[k]=1;
	while(!q.empty()){
		int tmp= q.front();
		q.pop();
		for(int i=0; i<G2[tmp].size(); i++){
			int t=G2[tmp][i];
			if(grass2[t] < grass2[tmp] + num[t]){
				grass2[t] = grass2[tmp] + num[t];
				if(!vis[t]){
					vis[t]=1;
					q.push(t);
				}
			}
		}
		vis[tmp]=0;
	}
}
int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
	}
	for(int i=1; i<=n; i++){
		if(!dfn[i])
			tarjan(i);
	}
	//cout << cnt << endl;
	int beg=color[1];
	for(int i=1; i<=n; i++){
		for(int j=0; j<G[i].size(); j++){
			int t=G[i][j];
			if(color[i] != color[t]){
				G1[color[i]].push_back(color[t]);
				G2[color[t]].push_back(color[i]);
			}
		}
	}
	spfa1(beg);
	spfa2(beg);
	int ans=num[beg];
	/*
	for(int i=1; i<=col; i++){
		cout << grass1[i] << " ";
	}
	cout << endl;
	for(int i=1; i<=col; i++){
		cout << grass2[i] <<" ";
	}
	cout << endl;
	for(int i=1; i<=col; i++)
		cout << num[i] <<" ";
	cout << endl;
	*/
	for(int i=1; i<=col; i++){
		if(grass1[i] != -1){
			for(int j=0; j<G2[i].size(); j++){
				int t=G2[i][j];
				if(grass2[t] != -1)
					ans = max(ans, grass2[t]+grass1[i]);
			}
		}
	}
	cout << ans - num[beg]<<endl;
	return 0;
}
