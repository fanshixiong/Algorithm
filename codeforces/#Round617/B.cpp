#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;

void solve(){
    ll x;
    cin >> x;
    ll ans = 0;
    while(x / 10){
        ans += (x - x % 10);
        x = x / 10 + x % 10;
    }
    ans += x;
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}