#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];

vector<int> G[maxn];
int dep[maxn], cnt[maxn];
void dfs(int u, int fa){
    cnt[u] = 1;
    for(auto v : G[u]){
        if(v == fa) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
}
void solve(){
    int n, k; cin >> n >> k;
    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dep[1] = 1;
    dfs(1, -1);
    for(int i = 1; i <= n; i++) a[i] = dep[i] - cnt[i];
    sort(a + 1, a + 1 + n);
    ll ans = 0;
    for(int i = n; i > n-k; i--) ans += a[i];
    cout << ans << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}