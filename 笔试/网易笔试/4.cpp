#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int f[maxn];
int main(){
	int t, y, x;
	cin >> t >> y;
	vector<int> a;
	while(cin >> x){
		if(cin.get() == '\n') break;
		// cout << x << endl;
	 	a.emplace_back(x);
	}

	sort(a.begin(), a.end());

	int n = a.size();
	memset(f, 0x3f, sizeof f);

	for(int i = 0; i <= t; i++){
		if(i <= a[0]) f[i] = a[0];
	}

	for(int i = 1; i <= n; i++){
		for(int j = t; j >= 0; j--){
			if(j <= a[i-1]){
				f[j] = min(a[i-1], f[j]);
			}
			else{
				f[j] = min(a[i-1]+f[j-a[i-1]], f[j]);
			}
		}
	}
	cout << f[t] - y << endl;
	return 0;
}