#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 5e5+10;
vector<int> G[maxn];
bool vis[maxn];
ll cnt=0;
void dfs(int a, int b){
    if(a==b)    
        return;
    vis[a] = 1;
    cnt++;
    for(int i=0; i<G[a].size(); i++){
        int t=G[a][i];
        if(!vis[t] ){
            dfs(t, b);
        }
    }
}
void solve(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    for(int i=1; i<=n; i++){
        G[i].clear();
    }
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    ll ans = 0;
    cnt=0;
    dfs(a, b);
    memset(vis, 0, sizeof(vis));
    ans = n-cnt-1;
    cnt = 0;
    dfs(b, a);
    ans = (ans) * (n-cnt-1);
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}