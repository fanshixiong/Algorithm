#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
vector<vector<int> > G(1000);
vector<int> color(1000), low(1000), dfn(1000);
vector<bool> vis(1000);
int n, cnt, col;
stack<int> s;
void tarjan(int k){
	dfn[k]=low[k]=++cnt;
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
		while(s.top() != k){
			color[s.top()] = col;
			vis[s.top()] = 0;
			s.pop();
		} 
		s.pop();
	}
} 
int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		int x; cin >> x;
		while(x){
			G[i].push_back(x);
			cin >> x;
		}
	}
	for(int i=1; i<=n; i++)
		if(!dfn[i])
			tarjan(i);
	vector<int> in(1000), de(1000);
	for(int i=1; i<=n; i++){
		for(int j=0; j<G[i].size(); j++){
			if(color[i] != color[G[i][j]]){
				in[color[G[i][j]]]++;
				de[color[i]]++;
			}
		}
	}
	int ansin=0, ansout=0;
	for(int i=1; i<=col; i++){
		if(in[i] == 0)
			ansin++;
		if(!de[i])
			ansout++; 
 	}
 	if(col == 1){
 		cout << 1 << endl << 0 << endl;
 		return 0;
	}
	cout << ansin << endl << max(ansin, ansout) <<endl;
	return 0;
}
