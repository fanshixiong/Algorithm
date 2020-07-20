#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    ll l, r, m;
    cin >> l >> r >> m;
    ll a, b, c;
    for (ll i = l; i <= r; i++){
        ll x1 = m % i, x2 = i - m % i;
        a = i;
        if(x2 <= r-l){
            b = l;
            c = x2 + l;
            break;
        }
        else if(x1 <= r-l){
            b = x1 + l;
            c = l;
            break;
        }
    }
    cout << a << " " << b << " " << c << endl;
}
int main(){ 
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}