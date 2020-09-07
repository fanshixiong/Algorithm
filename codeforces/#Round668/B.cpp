#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];
void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0, tmp = 0;
    for (int i = 0; i < n; i++){
        tmp += a[i];
        ans = max(ans, -1 * tmp);
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