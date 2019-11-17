#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		int n, k, p;
		cin >> n >> k >> p;
		int a[n];
		int mina=0, maxa=0;
		for(int i=0; i<n; i++){
			cin >> a[i];
		}
		if(!p){
			if(k%2){
				sort(a, a+n);
				cout << a[n-1] <<endl;
			}
			else{
				int ans=max(a[1], a[n-2]);
				for(int i=1; i<n-1; i++){
					ans = max(ans, min(a[i-1], a[i+1]));
				}
				cout << ans << endl;
			}
		}
		else{
			if(k%2){
				sort(a, a+n);
				cout << a[0] <<endl;
			}
			else{
				int ans=min(a[1], a[n-2]);
				for(int i=1; i<n-1; i++){
					ans = min(ans, max(a[i-1], a[i+1]));
				}
				cout << ans << endl;
			}
		}
		
	}
	return 0;
}
