#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 1e4 + 10;
ll a[maxn];
void solve(){
    ll n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> a[i];
    ll sum = 0;
    for(int i = 0; i < m; i++) sum += a[i];

    if(sum <= n)  cout << n - sum << endl;
    else cout << -1 << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}