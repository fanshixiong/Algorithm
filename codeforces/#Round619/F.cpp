#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, m, k, q;
vector<pair<int, int> > col[45];
int a[maxn][maxn], dist[45][maxn][maxn], vis[maxn][maxn], viscol[45];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void bfs(int _){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            vis[i][j] = 0;
        }
    }

    for (int i = 1; i <= k; i++)
        viscol[i] = 0;
    viscol[_] = 1;
    queue<pair<int ,int> > q;
    for(auto x:col[_]){
        q.push(x);
        dist[_][x.first][x.second] = 0;
        vis[x.first][x.second] = 1;
    }   
    while(!q.empty()){
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();
        if(!viscol[a[tx][ty]]){
            for(auto x : col[a[tx][ty]]){
                int nx = x.first;
                int ny = x.second;
                if(!vis[nx][ny] ){
                    dist[_][nx][ny] = dist[_][tx][ty] + 1;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            vis[tx][ty] = 1;
        }
        for (int i = 0; i < 4; i++){
            int nx = tx + dx[i];
            int ny = ty + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(!vis[nx][ny] ){
                dist[_][nx][ny] = dist[_][tx][ty] + 1;
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}


int main(){
    //ios_base::sync_with_stdio(0);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            scanf("%d", &a[i][j]);
            col[a[i][j]].push_back({i, j});
        }
    }
    for (int i = 1; i <= k; i++)
        bfs(i);
    scanf("%d", &q);
    while(q--){
        int r1, c1, r2, c2;
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        r1--, c1--, r2--, c2--;
        int ans=abs(r2-r1) +  abs(c2-c1);
        for (int i = 1; i<=k; i++)
            ans = min(ans, dist[i][r1][c1] + dist[i][r2][c2] + 1);
        printf("%d\n", ans);
    }
    return 0;
}