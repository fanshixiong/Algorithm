#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];
void solve(){
    ll ans = 0;
    int n; cin >> n;

    int cnt = 0, x = n, c10 = 1;
    while(x){
        x /= 10;
        cnt++;
        c10 *= 10;
    }
    c10 /= 10;
    int t = n / c10;
    // cout << c10 << " " << cnt << " " << t << endl;
    ans += (t - 1) * 10;
    cout << ans + (1 + cnt) * cnt / 2 << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}