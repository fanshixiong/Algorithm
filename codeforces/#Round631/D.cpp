#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    ll n, m;
    cin >> n >> m;
    ll ans = 1, i = 1;
    while((1 << (i-1))-1 <= n){
        ll t = min(n, (ll)((1 << i) - 1)) - ((1 << (i - 1)) - 1);
        ans = (ans * (t + 1)) % m;
        i++;
    }
    cout << (ans - 1 + m) % m << endl;
}
int main(){
    IOS;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}