#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
ll f[maxn], w[maxn];
void solve(){
    int n, m; cin >> n >> m;
    f[0] = 1;
    ll v;
    for(int i = 1; i <= n; i++){
        cin >> v;
        for (int j = v; j <= m; j++)
            f[j] += f[j - v];
    }
    cout << f[m] << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}