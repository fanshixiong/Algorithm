#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    if (n * (b + a) < (c - d) || n * (a - b) > (c + d)) cout << "NO" << endl;
    else cout << "Yes" << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}