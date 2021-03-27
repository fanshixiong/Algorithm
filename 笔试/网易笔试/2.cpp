#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int f[maxn][6];
int a[maxn];
int main(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];

	f[0][0] = 0;
	for(int i = 1; i < 6; i++) f[0][i] = -0x3f3f3f3f;

	for(int i = 1; i <= n; i++){
		int x = a[i] % 6;
		f[i][0] = max(f[i-1][0], f[i-1][(6-x)%6] + a[i]);
		f[i][1] = max(f[i-1][1], f[i-1][(6-x+1)%6] + a[i]);
		f[i][2] = max(f[i-1][2], f[i-1][(6-x+2)%6] + a[i]);
		f[i][3] = max(f[i-1][3], f[i-1][(6-x+3)%6] + a[i]);
		f[i][4] = max(f[i-1][4], f[i-1][(6-x+4)%6] + a[i]);
		f[i][5] = max(f[i-1][5], f[i-1][(6-x+5)%6] + a[i]);
	}
	cout << (f[n][0] == 0 ? -1 : f[n][0]) << endl;
	return 0;
}