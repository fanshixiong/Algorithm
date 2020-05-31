#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int n, k; cin >> n >> k;
    int ans = n;
    for (int j = 1; j * j <= n; j++) {
		if (n % j == 0) {
			if (j <= k) ans = min(ans, n / j);
			if (n / j <= k) ans = min(ans, j);
		}
    }
    
    cout << ans << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}