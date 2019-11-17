#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
const int m=1e6+10;
int a[maxn];
int vis[m];
int n, k, d;
 
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		cin >> n >> k >>d;
		for(int i=0; i<n; i++)
			cin >> a[i];
		int ans=0, res=d;
		int l=0, r=d-1;
		for(int i=0; i<d; i++){
			if(!vis[a[i]])
				ans++;
			vis[a[i]]++;
		}
		res = min(res, ans);
		//cout << ans << " "; 
		for(int i=d; i<n; i++){
			if(vis[a[i-d]]==1)
				ans--;
			vis[a[i-d]]--;
			if(!vis[a[i]]){
				ans++;
			}
			vis[a[i]]++;
			res = min(res, ans);
			//cout << ans << " ";
		}
		//cout << endl;
		cout << res << endl;
	}
	return 0;
} 
