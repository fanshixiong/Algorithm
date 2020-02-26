#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;
int n, q;
vector<int> G[maxn];
int fa[maxn][21], depth[maxn];


void dfs(int u, int f){
    fa[u][0] = f;
    for (int i = 1; i <= 20; i++){
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(f != v){
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}
int lca(int x, int y){
    int u = x, v = y;
    if(depth[u] < depth[v])
        swap(u, v);
    for (int i = 20; i >= 0; i--){
        if(depth[fa[u][i]] >= depth[v]){
            u = fa[u][i];
        }
    }
    if(u == v)   return abs(depth[x] - depth[y]);
    for (int i = 20; i >= 0; i--){
        //if(depth[fa[u][i]] != depth[fa[v][i]]){ //为啥我也不知道...
        if(fa[u][i] != fa[v][i]){
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return depth[x] + depth[y] - 2 * depth[fa[u][0]];
}
bool check(int x, int y){
    return (y>=x) && (x & 1) == (y & 1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    depth[0] = 0;
    dfs(1, 0);
    cin >> q;
    while(q--){
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        if(check(lca(a, b), k) || check(lca(a, x)+lca(y, b) + 1, k) || check(lca(a, y) + lca(x, b) + 1, k)){
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}