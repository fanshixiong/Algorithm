#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int a[maxn], b[maxn];
void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];

	sort(b, b + m);
	
	for(int i = 0; i < n; i++){
		int l = 0, r = m;
		int ans = m;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(b[mid] >= a[i]){
				ans = mid;
				r = mid-1;
			} else l = mid+1;
		}
		//cout << ans << " " ;
		cout << m - ans << " ";
	}
	cout << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}