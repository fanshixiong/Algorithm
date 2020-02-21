/*
倍增+LCA
*/

#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
using namespace std;
const int maxn = 3e6 + 10;
int n, m;
struct node{
    int to, w;
    node(int y, int w):to(y), w(w){}
};
vector<node> G[maxn];
int depth[maxn], fa[maxn][20], dist[maxn];

void dfs(int u, int f){
    fa[u][0] = f;
    for (int i = 1; i < 20; i++){
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int i = 0; i < G[u].size(); i++){
        int v = G[u][i].to, wet = G[u][i].w;
        if(v!=f){
            dist[v] = dist[u] + wet;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

int lca(int x, int y){
    int u = x, v = y;
    if(depth[u] < depth[v])
        swap(v, u);
    for (int i = 19; i >= 0; i--){
        if(depth[fa[u][i]] >= depth[v]){
            u = fa[u][i];
        }
    }
    if(u==v)
        return abs(dist[x] - dist[y]);
    for (int i = 19; i >= 0; i--){
        if(depth[fa[u][i]] != depth[fa[v][i]]){
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return dist[x] + dist[y] - 2 * dist[fa[u][0]];
}   
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    string s;
    for (int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        cin >> s;
        G[x].push_back(node(y, w));
        G[y].push_back(node(x, w));
    }
    depth[1] = 1;
    int k;
    dfs(1, 0);
    cin >> k;
    while(k--){
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }
    return 0;
}