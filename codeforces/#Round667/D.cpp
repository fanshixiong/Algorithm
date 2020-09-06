#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
ll sum(ll n){
    ll ans = 0;
    while(n){
        ans += (n % 10);
        n /= 10;
    }
    return ans;
}
void solve(){
    ll n, s; cin >> n >> s;
    if(sum(n) <= s){
        cout << 0 << endl;
        return;
    }
    ll pw = 1;
    ll ans = 0;
    for (int i = 0; i < 18; i++){
        ll digit = (n / pw) % 10;
        ll add = pw * ((10 - digit) % 10);
        ans += add;
        n += add;
        if(sum(n) <= s) break;
        pw *= 10;
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