#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    ll x, y, a, b; cin >> x >> y >> a >> b;
    if(a + a < b){
        cout << (x + y) * a << endl;
        return;
    }
    ll m = abs(x - y);
    ll ans = m * a + min(x, y) * b;
    cout << ans << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
/*
1
11 47
8 101
*/