#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3010;
ll dp[maxn][maxn];
int cnt[maxn][maxn], fa[maxn][maxn];
vector<int> tree[maxn];
int n, root;
void dfs(int u){
    cnt[root][u] = 1;
    for(int v: tree[u]){
        if(v == fa[root][u])
            continue;
        fa[root][v] = u;
        dfs(v);
        cnt[root][u] += cnt[root][v];  
    }
}
ll getDP(int u, int v){
    if(u == v)
        return 0;
    if(dp[u][v] != -1)
        return dp[u][v];
    dp[u][v] = cnt[u][v] * cnt[v][u] + max(getDP(fa[v][u], v), getDP(u, fa[u][v]));
    return dp[u][v];
}
int main(){
    ios_base::sync_with_stdio(0);
    memset(fa, -1, sizeof(fa));
    memset(cnt, -1, sizeof(cnt));
    cin >> n;
    for (int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    for (int u = 0; u<n; u++){
        root = u;
        dfs(u);
    }
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            ans = max(ans, getDP(i, j));
        }
    }
    cout << ans << endl;
    return 0;
}