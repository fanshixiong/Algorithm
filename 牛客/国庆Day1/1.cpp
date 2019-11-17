#include<bits/stdc++.h>
using namespace std;

int a[12][12];
int main(){
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF){
        int ans = 0;
        int lx=10, ly=10, rx=0, ry=0;
		for(int i=0; i<n; i++){
			string s;
			cin >> s;
			for(int j=0; j<m; j++){
				if(s[j]=='1'){
					lx = min(lx, i);
					ly = min(ly, j);
					rx = max(rx, i);
					ry = max(ry, j);
					ans++;
				}
			}
		}
		if((ry-ly+1)*(rx-lx+1) == ans){
			cout << "Yes" << endl;
		}
		else
			cout << "No" << endl;
	}
	return 0;
}
