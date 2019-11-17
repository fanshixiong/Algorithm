 #include <iostream>
 #include <cmath>
 #include <vector>
 #include <algorithm>
 #include <queue>
 using namespace std;
 vector<int> par(50010);
 struct node{
 	int beg, end, step;
 	node(){
 		step=1;
	 }
 };
 int Find(int x){
 	if(x==par[x])
 		return x;
 	return par[x]=Find(par[x]);
 }
 void Union(int x, int y){
 	x=Find(x);
 	y=Find(y);
 	if(x!=y)
 		par[x]=y;
 }
 int main(){
 	int n, k;
 	cin >> n >> k;
 	bool b=0;
 	for(int i=1; i<=n; i++)
 		par[i]=i;
 	vector<vector<node> > G(n+1); 
 	for(int i=0; i<k; i++){
 		int x, y, z;
 		cin >> x >> y >> z;
 		if(x==2){
 			Union(y, z);
 			node tmp;
 			tmp.beg=y;
			tmp.end=z;tmp.step=2;
			G[y].push_back(tmp); 
		}
		if(x==1){
			if(par[y]==par[z])
				b=1;
		}
		
	}
	if(b){
		cout << 1 << endl;
		return 0;
	}
	queue<node> q;
	node tmp;
	vector<bool> vis(n+1);
	for(int j=1; j<=n; j++){
		if(!vis[j] && G[j].size()>0){
			vis[j]=1;
			tmp.end=j; tmp.step=1;
			q.push(tmp);
			while(!q.empty()){
				tmp=q.front();
				q.pop();
				//cout << j << tmp.end << tmp.step << endl;
				for(int i=0; i<G[tmp.end].size(); i++){
					node tp=G[tmp.end][i];
					tp.step=tmp.step+1;
					
					if(tp.step >= 4){
						cout << 1 << endl;
						return 0;
					}
					if(!vis[tp.end]){
						q.push(tp); 
						vis[tp.end]=1;
					}
				}
			}
		}
	}
	cout<<0<<endl;
 	return 0;
 } 
