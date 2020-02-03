#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;

vector<int> G[maxn];
int vis[maxn], sum[maxn];

int bfs(int u){
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(u);
    int t;
    while(q.size()){
        t = q.front();
        q.pop();
        for (int i = 0; i < G[t].size(); i++){
            int v = G[t][i];
            if(!vis[v] && v != u){
                q.push(v);
                vis[v] = vis[t] + 1;
            }
        }
    }
    return t;
}
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1, x, y; i<n; i++){
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int u = bfs(1), v = bfs(u), ans = 0, w;
    for (int i = 1; i <= n; i++)
        sum[i] = vis[v] + vis[i];
    bfs(v);
    for (int i = 1; i <= n; i++){
        sum[i] += vis[i];
        if(i != u && i != v && sum[i] > ans)
            ans = sum[i], w = i;
    }
    cout << ans/2 << endl << u << " " << v << " " << w << endl;
    return 0;
}