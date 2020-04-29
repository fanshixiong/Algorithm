#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
ll a[maxn];
void solve(){
    int n; cin >> n;
    memset(a, 0, sizeof a);
    for (int i = 0; i < n; i++) cin >> a[i];
    int flg = a[0] > 0 ? 1 : -1;
    ll ans = 0, maxx = a[0];
    for (int i = 0; i < n; i++){
        if(flg > 0 && a[i] > 0) maxx = max(maxx, a[i]);
        else if(flg < 0 && a[i] < 0) maxx = max (maxx, a[i]);
        else{
            flg = -1 * flg;
            ans += maxx;
            maxx = a[i];
        }
    }
    ans += maxx;
    cout << ans << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}