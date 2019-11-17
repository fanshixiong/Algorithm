#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
using namespace std;
vector<vector<int> > G;
vector<int> dfn(50004), low(50004), color(50004), cnt(50004);
stack<int> s;
int col=0, step=0;
int N, M;
void tarjan(int k){
	dfn[k]=low[k]=++step;
	s.push(k);
	for(int i=0; i<G[k].size(); i++){
		int t=G[k][i];
		if(!dfn[t]){
			tarjan(t);
			low[k]=min(low[t], low[k]);
		}
		else if(!color[t]){
			low[k]=min(low[t], low[k]);
		}
	} 
	if(dfn[k]==low[k]){
		color[k]=++col;
		cnt[col]++;
		while(s.top()!=k){
			color[s.top()]=col;
			cnt[col]++;
			s.pop();
		}
		s.pop();
	}
}
int main(){
	cin >> N >> M;
	G.resize(N+1);
	int x, y, n;
	for(int i=0; i<M; i++){
		cin >> x >> y >> n;
		if(n==1){
			G[x].push_back(y); 
		}
		else if(n==2){
			G[y].push_back(x); 
			G[x].push_back(y); 
		}
	}
	for(int i=1; i<=N; i++){
		if(!dfn[i])
			tarjan(i);
	}
	int ans=0;
	for(int i=0; i<=col; i++){
		ans=max(ans, cnt[i]);
	}
	cout << ans << endl;
	for(int i=1; i<=N; i++){
		if(ans == cnt[color[i]]){
			for(int j=i; j<=N; j++){
				if(color[i]==color[j])
					cout << j << " ";
			}
			return 0;
		}
	}
	return 0;
} 
