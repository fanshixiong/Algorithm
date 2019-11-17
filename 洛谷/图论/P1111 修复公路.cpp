#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> par(100005);
struct node{
	int from, to, value;
};
bool cmp(node &a, node &b){
	return a.value < b.value;
}
int Find(int x){
	if(x==par[x])
		return x;
	return par[x]=Find(par[x]);
}
int main(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		par[i]=i;
	}
	vector<node> G(m);
	for(int i=0; i<m; i++){
		int x, y, z;
		cin >> x >>y >> z;
		G[i].from=x; G[i].to=y; G[i].value=z;
	}
	sort(G.begin(), G.end(), cmp);
	int k=1;
	int ans=0;
	for(int i=0; i<m; i++){
		if(Find(G[i].from) != Find(G[i].to)){
			ans=max(ans, G[i].value);
			k++;
			par[Find(G[i].from)] = G[i].to;
			if(k == n){
				cout << ans << endl;
				return 0; 
			}
		}
	}
	cout << -1 << endl;
	return 0;
} 
