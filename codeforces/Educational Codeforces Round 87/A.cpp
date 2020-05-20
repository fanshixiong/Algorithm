#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(b >= a){cout << b << endl; return;}
    if(c <= d){cout << -1 << endl; return;}
    ll ans = b, rem = a - b - 1;
    ans += (rem / (c - d) + 1) * (c);
    cout << ans << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}