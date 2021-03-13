// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>
const int maxn = 1010;
vector<int> G[maxn];
int vis[maxn];
int dist[maxn][maxn];
int graph[maxn][maxn];
/*
int main() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        G[a].push_back(b);
    }
    memset(dist, 0x3f, sizeof dist);

    int q; cin >> q;
    queue<pi> qu;
    while(q--){
        int a, b; cin >> a >> b;
        memset(vis, 0, sizeof vis);
        qu.push({a, 0}); vis[a] = 1;
        while(!qu.empty()){
            auto x = qu.front(); qu.pop();
            int u = x.first, d = x.second;
            if(u == b){
                cout << d << endl;
                break;
            }
            //cout << u << " ss " << endl;
            for(auto v : G[u]){
                if(vis[v]) continue;
                qu.push({v, d+1});
                vis[v] = 1;
            }
        }
        cout << -1 << endl;
    }
    return 0;
}
*/
int main() {
    int n, m; cin >> n >> m;
    memset(dist, 0x3f, sizeof dist);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        dist[a][b] = 1;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }

    int q; cin >> q;
    while(q--){
        int a, b; cin >> a >> b;
        
        cout << (dist[a][b] == 0x3f3f3f3f ? -1 : dist[a][b]) << endl;
    }
    return 0;
}