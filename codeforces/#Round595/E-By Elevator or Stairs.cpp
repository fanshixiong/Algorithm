#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int a[maxn], b[maxn];
int ans[maxn][2];
int main(){
	ios::sync_with_stdio(0);
	int n, c;
	cin >> n >> c;
	//memset(ans, 0x3f3f3f, (n+1)*(n+1));
	for(int i=2; i<=n; i++)
		cin >> a[i];
	for(int i=2; i<=n; i++)
		cin >> b[i];
	ans[1][0]=0; ans[1][1]=c;
	for(int i=2; i<=n; i++){
		ans[i][0] = min(ans[i-1][0]+a[i], ans[i-1][1]+a[i]);
		ans[i][1] = min(ans[i-1][0]+c+b[i], ans[i-1][1]+b[i]);
	}
	for(int i=1; i<=n; i++){
		cout << min(ans[i][0], ans[i][1]) << " ";
	}
	cout << endl;
	return 0;
}
