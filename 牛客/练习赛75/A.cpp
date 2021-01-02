#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
ll a[maxn];
void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    bool flag = true;
	ll t = a[1] - a[0];
	for (int i = 0; i < n - 1; ++i){
    	if (a[i + 1] - a[i] != t){
        	flag = false;
        	break;
    	}
	}
	if(flag){
		cout << "YES" << endl;
		return;
	}
	
	flag = true;
	if(a[1] % a[0] != 0) flag = false;
	t = a[1] / a[0];
	for (int i = 0; i < n - 1; ++i){
		if(a[i] * t != a[i+1]){
        	flag = false;
        	break;
    	}
	}
	if(flag){
		cout << "YES" << endl;
		return;
	}

	flag = true;
	if(a[0] % a[1] != 0) flag = false;
	t = a[0] / a[1];
	for (int i = 0; i < n - 1; ++i){
		if(a[i] != a[i+1] * t){
        	flag = false;
        	break;
    	}
	}
	if(flag){
		cout << "YES" << endl;
		return;
	}
	
	flag = true;
	t = a[1] % a[0];
	for (int i = 0; i < n - 1; ++i){
		if(a[i+1] < a[i] || a[i+1] % a[i] != t){
        	flag = false;
        	break;
    	}
	}
	if(flag) cout << "YES" << endl; 
	else cout << "NO" << endl;

	// cout << 3 % 7 << " " << 7 % 4 << endl; 
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}