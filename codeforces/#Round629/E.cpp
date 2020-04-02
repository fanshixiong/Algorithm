#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 3e5 + 10;
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
    if(u == v)   //return abs(depth[x] - depth[y]);
        return u;
    for (int i = 20; i >= 0; i--){
        //if(depth[fa[u][i]] != depth[fa[v][i]]){ //为啥我也不知道...
        if(fa[u][i] != fa[v][i]){
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    //return depth[x] + depth[y] - 2 * depth[fa[u][0]];
    return fa[u][0];
}

int q[maxn];
bool cmp(int a, int b){
    return depth[a] > depth[b];
}
int main(){
    IOS;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    depth[0] = 0;
    dfs(1, 0);

    while(m--){
        int t; cin >> t;
        for (int i = 0; i < t; i++) cin >> q[i];
        sort(q, q + t, cmp);
        bool flg = 1;
        for (int i = 1; i < t; i++){
            if(depth[q[i]] == depth[q[i-1]]){
                if(fa[q[i]][0] != fa[q[i-1]][0]) flg = 0;
            }
            else{
                int rt = lca(q[i], q[i - 1]);
                //cout << q[i] << " " << rt << " " << fa[q[i]][0] << endl;
                if(rt != fa[q[i]][0] && rt != q[i]) flg = 0;
            }
        }
        cout << (flg ? "YES" : "NO") << endl;
    }
    return 0;
}
/*
10 6
1 2
1 3
1 4
2 5
2 6
3 7
7 8
7 9
9 10
4 3 8 9 10
8 3 7
3 2 1
NO
3 2 4 6
2 1 1
YES
3 2 1 5
2 1 1
1 1 0
YES
3 4 8 2
4 4 1
YES
2 6 10
6 6 2
YES
3 5 4 7
4 3 1
NO
*/