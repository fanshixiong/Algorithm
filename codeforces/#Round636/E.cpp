#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int da[maxn], db[maxn], dc[maxn];
ll p[maxn], sum[maxn]; //TLE
int vis[maxn];
vector<int> G[maxn];
void spfa(int s, int d[]){
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    d[s] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : G[u]){
            if(d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                if(!vis[v]){
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}
void solve(){
    int n, m, a, b, c; 
    cin >> n >> m >> a >> b >> c;
    for (int i = 0; i <= n; i++) G[i].clear(); //TLE
    
    memset(da, 0x3f3f3f3f, sizeof da);
    memset(db, 0x3f3f3f3f, sizeof da);
    memset(dc, 0x3f3f3f3f, sizeof da); 

    for (int i = 1; i <= m; i++) scanf("%lld", &p[i]); //cin >> p[i];
    sort(p + 1, p + m + 1);
    sum[0] = 0;
    for (int i = 1; i <= m; i++) sum[i] = sum[i-1] + p[i];
    for (int i = 1; i <= m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        //cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    spfa(a, da);
    spfa(b, db);
    spfa(c, dc);
    ll ans = 1e15;
    for (int i = 1; i <= n; i++){
        if(da[i] + db[i] + dc[i] > m)continue;
        ans = min(ans, 2 * sum[db[i]] + sum[da[i] + db[i] + dc[i]] - sum[db[i]]);
    }
    cout << ans << endl;
}
int main(){
    //IOS; int t; cin >> t;
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
/*
2
4 3 2 3 4
1 2 3
1 2
1 3
1 4
7 9 1 5 7
2 10 4 8 5 6 7 3 3
1 2
1 3
1 4
3 2
3 5
4 2
5 6
1 7
6 7
*/