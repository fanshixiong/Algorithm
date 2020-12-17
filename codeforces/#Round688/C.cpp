#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;

// 从后往前找
void solve(){
    int n, p, k;
    cin >> n >> p >> k;
    string a; cin >> a;

    ll x, y;
    cin >> x >> y;

    ll ans = 1e18;
    for(int i = n - k + 1; i <= n; i++){
        ll res = 0;
        for (int r = i; r >= 1; r-=k){
            if(a[r-1] == '0') res += x;
            ll t = r - p;
            if(t < 0) break;
            ll p = t * y + res;
            ans = min(ans, p);
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