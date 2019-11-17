#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
int cnt, col, m, n;
int color[105555], dfn[105555], low[105555], num[10005];
vector<int> G[100050];
bool vis[100050];
stack<int> s;
void tarjan(int k){
	dfn[k]=low[k]=++cnt;
	vis[k]=1;
	s.push(k);
	for(int i=0; i<G[k].size(); i++){
		int t=G[k][i];
		if(!dfn[t]){
			tarjan(t);
			low[k]=min(low[t], low[k]);
		}
		else if(vis[t]){       //if(!color[t]) 
			low[k] = min(low[t], low[k]);
		}
	} 
	if(dfn[k] == low[k]){
		vis[k]=0;
		color[k]=++col;
		num[col]++;
		while(s.top()!=k){
			color[s.top()]=col;
			num[col]++;
			vis[s.top()]=0;
			s.pop();
		}
		s.pop();
	}
}
int main(){
	cin >> n >> m; 
	for(int i=1; i<=m; i++){
		int x, y;
		cin >> x >>y;
		G[y].push_back(x); 
	}
	
	for(int i=1; i<=n; i++)
		if(!dfn[i])
			tarjan(i);
	vector<int> outde(n+1);
	for(int i=1; i<=n; i++){
		for(int j=0; j<G[i].size(); j++){
			if(color[i] != color[G[i][j]])   //错误点1 ，不能和i相同 
				outde[color[G[i][j]]]++; //outde[color[i]]++; 与上面建图方向相反 
		}
	}
	int ans=0, sign=0;
	for(int i=1; i<=col; i++){
		if(outde[i]==0){
			ans=num[i];
			sign++;       //错误点2 没有考虑两个初度为零的情况。 
		}
	}
	if(sign == 1)
		cout << ans << endl;
	else
		cout << 0 << endl;
	return 0;
}
