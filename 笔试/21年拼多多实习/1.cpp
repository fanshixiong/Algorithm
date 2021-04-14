#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	vector<int> a(220);
	for(int i = 0; i < n; i++) cin >> a[i];

	int ans = 0;
	for(int i = 1; i < n - 1; i++){
		if(a[i-1] >= a[i] || a[i+1] >= a[i]) continue;

		int l = i-1, r=i+1;
		while(l >= 0 && a[l] < a[l+1]) l--;
		while(r < n && a[r] < a[r-1]) r++;
		//cout << i << " " << l << " " << r << endl;
		ans = max(ans, r - l - 1);
	}
	cout << ans << endl;
	return 0;
}