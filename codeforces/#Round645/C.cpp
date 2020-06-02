#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << 1ll*(y2 - y1) * (x2 - x1) + 1 << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}