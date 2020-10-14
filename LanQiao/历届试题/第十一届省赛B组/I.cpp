#include<bits/stdc++.h>

using namespace std;

#define ll unsigned long long

const int maxn = 1e5+10;
int a[maxn];

int main(){
	ll n, k;
	cin >> n >> k;
	
	
	for(int i = 0; i < n; i++) cin >> a[i];
	
	ll ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			ostringstream os1;
			os1 << a[i];
			string t = os1.str();
			ostringstream os2;
			os2 << a[j];
			t += os2.str();
			istringstream is(t);
			ll sums;
			is >> sums;
			// cout << a[i] << " " << a[j] << " " << t << " " << sums << endl;
			if(sums % k == 0) ans++;
		}
	}
	cout << ans % 2020 << endl;
	return 0;
} 
/*
4 2
1 2 3 4
*/
