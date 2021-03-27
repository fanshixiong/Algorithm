#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
vector<int> a[maxn];
int b[maxn], pre[maxn];
void solve(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> b[i];
	int target; cin >> target;

	ll ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			int x = 0;
			for(int k = i; k <= j; k++) x |= b[k];
			if(x <= target) ans++;
		}
	}
	cout << ans << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}