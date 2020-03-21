#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn = 2e5 + 10;

int n, m, sq;
vector<int> G[maxn];
vector<int> ans1, ans2;
int dep[maxn], vis[maxn];


void dfs(int u){
    ans2.pb(u);
    dep[u] = ans2.size();
    for (int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(!dep[v])
            dfs(v);
        else if(dep[u] - dep[v] >= sq-1){
            cout << 2 << endl;
            cout << dep[u] - dep[v] + 1 << endl;
            for (int i = dep[v] - 1; i < dep[u]; i++){
                cout << ans2[i] << " ";
            }
            cout << endl;
            exit(0);
        }
    }
    if(!vis[u]){
        ans1.pb(u);
        for (int i = 0; i < G[u].size(); i++){
            int v = G[u][i];
            vis[v] = 1;
        }
    }
    ans2.pop_back();
}
int main(){
    ios_base::sync_with_stdio(0);
    memset(vis, 0, sizeof(vis));
    memset(dep, 0, sizeof(vis));
    cin >> n >> m;
    sq = sqrt(n - 1) + 1;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        G[x].pb(y);  G[y].pb(x);
    }
    dfs(1);
    cout << 1 << endl;
    for (int i = 0; i < sq; i++){
        cout << ans1[i] << " ";
    }
    cout << endl;
    return 0;
}