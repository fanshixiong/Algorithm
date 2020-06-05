#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
ll getR(ll a){
    while(a % 2 == 0) {a /= 2;}
    return a;
}
void solve(){
    ll a, b;
    cin >> a >> b;
    if(getR(a) != getR(b)){
        cout << -1 << endl;
        return;
    }

    if(a > b) swap(a, b); 
    b /= a;
    ll ans = 0;
    while(b >= 8) b /= 8, ans++;
    if(b > 1) ans++;
    cout << ans << endl;

}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}