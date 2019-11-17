#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
struct node{
	int end;
	int value;
};
vector<node> G[50050];
vector<bool> vis(50150);
int D[500010], x, a, b, c;
bool z;
void spfa(int k){
	vis[k]=true;
	for(int i=0; i<G[k].size(); i++){
		node t=G[k][i];
		if(D[t.end] > D[k] + t.value){
			if(vis[t.end]){
				z=true;
				return;
			}
			D[t.end] = D[k] + t.value; 
			spfa(t.end);
		}
	}
	vis[k]=false;
	return;
}
int main(){
	int m, n;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=m; i++){
		scanf("%d%d%d",&x,&a,&b);
		if(x==1){
			scanf("%d", &c);
			node tmp;
			tmp.end=b; tmp.value=-1*c;
			G[a].push_back(tmp);
		}
		else if(x==2){
			scanf("%d", &c);
			node tmp;
			tmp.end=a; tmp.value=c;
			G[b].push_back(tmp);
		}
		else{
			node tmp;
			tmp.end=a; tmp.value=0;
			G[b].push_back(tmp);
			tmp.end=b; tmp.value=0;
			G[a].push_back(tmp);
		}
	}
	z=0; 
	for(int i=1; i<=n; i++){
		D[i]=0;
		spfa(i);
		if(z)
			break;
	}
	if(z)
		cout << "No" <<endl;
	else
		cout << "Yes" <<endl;
	return 0;
}
