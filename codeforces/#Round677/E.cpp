#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 3e5 + 10;
int a[maxn], dp[maxn];
void solve(){
    int n; cin >> n;
    if(n <= 4){
        cout << (n == 2 ? 1 : 3) << endl;
        return;
    }
    n /= 2; n-=1;
    ll ans = 1;
    for (int i = 1; i <= 2 * n + 1; i++) if(i != n + 1) ans *= i;

    cout << ans << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}