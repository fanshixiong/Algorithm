
/**
 * 因为每棵子树都可以被包含进更大的子树中，所以对于每棵子树的根节点,
 * 它的最小选取代价可以取它自身和所有可能的父节点的最小值。
 * 计算每棵子树中需要交换的 0 和 1 的个数，用根节点的最小选取代价交换后，
 * 多余的 0 或 1 累加至父节点所在的子树即可。
 * */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e6 + 10;
ll cnt[maxn][2], a[maxn], b[maxn], c[maxn];
vector<int> G[maxn];
ll ans;

void dfs(int u, int fa){
    if(fa) a[u] = min(a[u], a[fa]);
    for(auto v:G[u]){
        if(v != fa){
            dfs(v, u);
            cnt[u][0] += cnt[v][0];
            cnt[u][1] += cnt[v][1];
        }
    }

    if(b[u] != c[u]) cnt[u][b[u]] ++;
    int tmp = min(cnt[u][0], cnt[u][1]);
    ans += 2ll * a[u] * tmp;
    cnt[u][0] -= tmp;
    cnt[u][1] -= tmp;
}
void solve(){
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];

    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, 0);
    cout << ((cnt[1][0] || cnt[1][1]) ? -1 : ans) << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}