#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 5e5 + 10;
ll a[maxn];
void solve(){
    int n; cin >> n;

    cout << a[n] << endl;
}
int main(){
    IOS; int t; cin >> t;
    a[1] = 0;
    for (ll i = 3, j = 1; i < maxn; i += 2, j++) a[i] = a[i-2] + 1ll * 4 *(i-1) * j;
    while(t--){
        solve();
    }
    return 0;
}