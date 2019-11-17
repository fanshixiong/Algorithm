  #include <iostream>
 #include <cmath>
 #include <vector>
 #include <algorithm>
 #include <queue>
 using namespace std;
 struct node{
 	int end, step;
 };
 int main(){
 	int n, anc;
 	long long ans=0;
 	cin >> n;
 	vector<vector<node> > G(10010);
 	for(int i=1; i<n; i++){
 		int x, y;
 		cin >> x >> y;
 		node tp;
 		tp.end=y; tp.step=1;
 		G[x].push_back(tp);
 		tp.end=x;
 		G[y].push_back(tp); 
	}
	cin >> anc;
	queue<node> q;
	vector<bool> vis(n+1);
	node tp;
	tp.end=anc; tp.step=0;
	q.push(tp); vis[anc]=1;
	while(!q.empty()){
		node tmp=q.front();
		q.pop();
		//cout << tmp.end << tmp.step << endl;
		for(int i=0; i<G[tmp.end].size(); i++){
			int m=G[tmp.end][i].end;
			if(!vis[m]){
				node t;
				vis[m]=1;
				t.end=m; t.step=tmp.step+1;
				q.push(t);
				ans+=t.step; 
			}
		}
	}
	cout << ans << endl;
 	return 0;
 } 
