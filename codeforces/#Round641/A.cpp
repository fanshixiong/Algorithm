#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 1e6 + 10;
int f[maxn];

void solve(){
    int n, k; cin >> n >> k;
    int f = 0;
    for (int i = 2; i <= n; i++){
        if(n % i == 0){
            f = i;
            break;
        }
    }
    if(n % 2){
        n += f;
        k--;
    }
    f = 2;
    ll ans = 1ll * n + 1ll * k * f;
    cout << ans << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}