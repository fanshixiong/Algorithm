#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 1e5 + 10;
int dep[maxn];
vector<int> G[maxn];
bool flg;
void dfs(int u, int fa, int depth){
    dep[u] = depth;
    if (G[u].size() == 1 && (depth & 1)) flg = true;
    for (int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i];
        if (v == fa) continue;
        dfs(v, u, depth + 1);
    }
}
void solve(){
    int n; cin >> n;
    for (int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int root = -1;
    for (int i = 1; i <= n; i++){
        if(G[i].size() == 1){
            root = i; break;
        }
    }
    dfs(root, -1, 0);
    int minn = flg ? 3 : 1;
    int ans = n - 1;
    for (int i = 1; i <= n; i++){
        int cnt = 0;
        for(auto v : G[i]){
            if(G[v].size() == 1) cnt++;
        }
        ans -= max(0, cnt - 1);
    }
    cout << minn << " " << ans << endl;
}
int main(){
    IOS;  int t = 1;
    while(t--){
        solve();
    }
    return 0;
}