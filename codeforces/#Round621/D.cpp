#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5+10;

int n, m, k;
int dist[2][maxn], a[maxn];
bool vis[maxn];
vector<int> G[maxn];

void bfs(int _, int u){
    for (int i = 1; i <= n; i++)
        dist[_][i] = 0x3f3f;
    dist[_][u] = 0;
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    vis[u] = 1;
    q.push(u);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for (int i = 0; i < G[t].size(); i++){
            int v = G[t][i];
            if(!vis[v]){
                vis[v] = 1;
                dist[_][v] = dist[_][t] + 1;
                q.push(v);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
        cin >> a[i];
    for (int i = 0; i<m; i++){
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    bfs(0, 1);
    //for (int i = 1; i <= n; i++)
    //    cout << dist[0][i] << endl;
    bfs(1, n);
    vector<pair<int, int> >  v;
    for(int i=0; i<k; i++){
        v.push_back({dist[0][a[i]] - dist[1][a[i]], a[i]});
    }
    sort(v.begin(), v.end());
    int tmp = 0, ans = 0;
    for(int i=0; i<v.size(); i++){
        if(i) ans = max(ans, tmp + 1 + dist[1][v[i].second]);
        tmp = max(tmp, dist[0][v[i].second]);
    }
    //cout << ans << dist[1][1] << endl;
    cout << min(dist[0][n], ans) << endl;
    return 0;
}