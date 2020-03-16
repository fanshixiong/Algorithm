#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn], dp[maxn], ans[maxn];
vector<int> G[maxn];
void dfs1(int v, int fa){
    dp[v] = a[v];
    for (auto u : G[v]){
        if(u == fa)
            continue;
        dfs1(u, v);
        dp[v] += max(dp[u], 0);
    }
}
void dfs2(int v, int fa, int sum){
    ans[v] = sum + dp[v];
    for (auto u: G[v]){
        if(u == fa)
            continue;
        dfs2(u, v, max(0, ans[v] - max(0, dp[u])));
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 0)  a[i] = -1;
    }
    for (int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs1(1, -1);
    dfs2(1, -1, 0);
    for (int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}