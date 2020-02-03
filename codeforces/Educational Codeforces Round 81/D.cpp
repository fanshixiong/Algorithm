#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;
ll phi(ll x){
    ll ans = x;
    for (ll i = 2; i * i <= x; i++){
        if(x % i == 0){
            ans -= ans / i;
            while(x % i == 0)
                x /= i;
        }
    }
    if(x > 1)
        ans -= ans / x;
    return ans;
}
void solve(){
    ll a, m;
    cin >> a >> m;
    cout << phi(m / __gcd(a, m)) << endl;
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