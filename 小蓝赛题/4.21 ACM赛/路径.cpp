#include <iostream>
#include<vector>
using namespace std;
int main(){
	int n, m; cin >> n >>m;
	vector<vector<int> > G(n+1);
	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int q; cin >> q;
	while(q--){
		int beg, end; 
		cin >> beg >> end;
		vector<vector<int> > D(n+1, vector<int> (n+1, 0x3f3f3f3f));
		for(int i=1; i<=n; i++){
			for(int j=0; j<G[i].size(); j++){
				int t=G[i][j];
				D[i][t]=D[t][i]=1;
			}
		}
		for(int k=1; k<=n; k++){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++)
					if(D[i][j] > D[i][k]+D[k][j])
						D[i][j] = D[i][k] + D[k][j];
			}
		}
		long ans=2;
		for(int i=1; i<=n; i++){
			if(D[beg][i] + D[i][end] == D[beg][end])
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
