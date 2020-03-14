#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
bool vis[maxn];
int dist[maxn], cnt[maxn], p[maxn];
int n, m, k;
vector<int> G[maxn];

void spfa(int u){
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    memset(cnt, 0, sizeof(dist));
    memset(vis, false, sizeof(vis));

    queue<int> q;
    vis[u] = true;
    dist[u] = 0;
    q.push(u);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        vis[t] = false;
        for (int i = 0; i < G[t].size(); i++){
            int p = G[t][i];
            if(dist[p] > dist[t] + 1){
                dist[p] = dist[t] + 1;
                cnt[p] = 1;
                if(!vis[p]){
                    q.push(p);
                    vis[p] = true;
                }
            }
            else if(dist[p] == dist[t] + 1)
                cnt[p]++;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        G[y].push_back(x);
    }
    cin >> k;
    for (int i = 0; i < k; i++){
        cin >> p[i];
    }
    spfa(p[k-1]);
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < k; i++){
        if(dist[p[i]]-1 < dist[p[i+1]]){
            ans1++; ans2++;
            continue;
        }
        if (cnt[p[i]] > 1)
            ans2++;
    }
    cout << ans1-1 << " " << ans2-1 << endl;
    return 0;
}