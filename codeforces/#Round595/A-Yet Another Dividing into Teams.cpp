#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	ios::sync_with_stdio(0);
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		memset(a, 0, sizeof(a));
		bool b=0;
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			if(a[x-1] || a[x+1]){
				b=1;
			}
			a[x]++;
		}
		if(b)
			cout << 2<< endl;
		else
			cout << 1 << endl;
	}
	return 0;
}
