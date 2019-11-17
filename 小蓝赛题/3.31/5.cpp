#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
int N[501][501]={0};
int main(){
	cin >> n >> m;
	int x;
	for (int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> x;
			if (x==0) x=-0x3f3f3f;
			N[i][j] = N[i-1][j]+x;
		}
	}
	
	int ans=-0x3f3f3f3f;
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			int num=0;
			for(int k=1; k<=m; k++){
				num+=N[j][k]-N[i-1][k];
				ans = max(ans, num);
				if(num<0) num=0;
			}
			
		}
	}
	cout << ans << endl;
	return 0;
}
