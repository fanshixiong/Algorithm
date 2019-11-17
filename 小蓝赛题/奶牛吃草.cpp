#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int step=0, col=0, ans=0;
class Cow{
	int N, M, best;					//草地数量 与路径数 
	vector<int> glass;
	vector<int> glass2;
	vector<vector<int> > graph;
	vector<vector<int> > graph2;
	vector<int> dfn, low, color;
	vector<bool> vis;
	stack<int> s;
public:
	Cow(){
		best=0;
		cin >> N >> M;
		vis.resize(N+1); 
		glass.resize(N+1); 
		for (int i = 1; i <= N; i++){
			cin >> glass[i];
		}
		graph.resize(N+5);
		graph2.resize(N+5);
		for (int i = 1; i <= M; i++){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
		}
	}
	void tarjan(int k){
		dfn[k]=++step;
		low[k]=step;
		vis[k]=1;
		s.push(k);
		for(int i=0; i<graph[k].size(); i++){
			int t=graph[k][i];
			if(!dfn[t]){
				tarjan(t);
				low[k]=min(low[t], low[k]);
			}
			else if(vis[t]){
				low[k]=min(low[t], low[k]);
			}
		}
		if(dfn[k]==low[k]){
			color[k]=++col;
			vis[k]=0;
			while(s.top()!=k){
				color[s.top()]=col;
				vis[s.top()]=0;
				s.pop();
			}
			s.pop();
		}
	}
	void dfs(int k){
	//cout << k << " " << glass2[k] << endl;
		if(ans>best){
			best=ans;
		}
		for(int i=0; i<graph2[k].size(); i++){
			int t=graph2[k][i], tp=glass2[t];
			ans+=tp; glass2[t]=0;
			dfs(t);
			ans-=tp; glass2[t]=tp;
		}
	}
	void resolve(){
		glass2.resize(N+5);
		dfn.resize(N+5);
		low.resize(N+5);
		color.resize(N+5); 
		for(int i=1; i<=N; i++){
			if(!dfn[i]){
				tarjan(i);
			}
		}
		for(int i=1; i<=N; i++)	
			vis[i]=0;
		for(int i=1; i<=N; i++){
			glass2[color[i]] += glass[i];
			for(int j=graph[i].size()-1; j>=0; j--){
				int t=graph[i][j];
				if(color[t]!=color[i]){
					graph2[color[i]].push_back(color[t]); 
				}
			}
		}
		/*
		for(int i=1; i<=N; i++)
			cout << color[i] <<" ";
		cout << endl;
		for(int i=1; i<col; i++)
			cout << glass2[i] << " ";
		cout << endl;*/
		dfs(color[1]);
		cout << best+glass2[color[1]] << endl;
	}
};
int main(){
	Cow test;
	test.resolve();
	return 0;
}
