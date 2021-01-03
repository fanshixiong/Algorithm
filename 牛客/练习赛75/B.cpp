#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e3 + 10;
ll n, m, k;
ll a[maxn], b[maxn];
ll dp[maxn];
void solve(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];

	if(n == 2 || k == 0){
		if(n == 2 && (k & 1)) if(a[0] * b[1] > a[1] * b[0]) swap(b[0], b[1]);

		for (int i = 0; i < n; i++) {
            for (int j = a[i]; j <= m; j++) {
                dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
            }
        }
 
		cout << dp[m] << endl;
	}
	else{
		ll ma = 0, mi = 0x3f3f3f3f;
		for(int i = 0; i < n; i++){
			ma = max(ma, b[i]);
			mi = min(mi, a[i]);
		}
		cout << m / mi * ma << endl;
	}
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
/*
2 5 1
1 3 
1 2
*/