#include<bits/stdc++.h>
using namespace std;

//floyd

const int maxn = 300+10;
int G[maxn][maxn];
int n, m;

void solve(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			G[i][j] = 0x3f3f3f3f;
		}
	}
	while(m--){
		int u, v, w;
		scanf("%d%d%d", &u,&v,&w);
		u++; v++;
		G[u][v] = w;
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i != j)
					G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
			}
		}
	}
	for(int i=1; i<=6; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		u++; v++;
		printf("%d\n", -G[v][u]);
		G[u][v] = -G[v][u];
		for(int k=1; k<=max(u, v); k++){///k<=n runtime
			for(int p=1; p<=n; p++){
				for(int q=1; q<=n; q++){
					if(p!=q)
						G[p][q] = min(G[p][q], G[p][k]+G[k][q]);
				}
			}
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
