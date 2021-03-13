#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m; cin >> n >> m;
	vector<vector<int> > a(n+1, vector<int>(m+1));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			cout << a[j][i] << " ";
		}
		cout << endl;
	}
	return 0;
}