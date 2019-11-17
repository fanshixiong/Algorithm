#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define ll unsigned long long
const int N = 1e4+5;
ll n, m;
int par[N][2];
//int G[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	//memset(G, 0, sizeof(G)); 
	for(int i=1; i<n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		//G[a][b] = c;
		par[b][0]=a;
		par[b][1]=c; 
	}
	
	par[1][0]=0;
	ll res=0, ans=0;
	while(m--){
		ll tp=0;
		int u, v;
		cin >> u >> v;
		while(v!=u && v!=0){
			//tp += G[par[v]][v];
			//v=par[v];
			tp += par[v][1];
			v = par[v][0];
		}
		if(v == u){
			ans += tp;
			res++;
		}
	}
	cout << res << endl << ans << endl;
	return 0;
}
