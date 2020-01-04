#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m;
int cas, tot;

vector<int> g[maxn];
int p[maxn], q[maxn], pos[maxn];
bool vis[maxn];

struct E{
    int a, b, c, cnt;
} e[maxn];

void put(int u, int v){
    if(pos[v])
        return;
    int x = pos[u], y;
    y = (x - 1 == 0 ? n : x - 1);
    if(!p[y]){
        p[y] = v;
        pos[v] = y;
        return;
    }
}

void dfs(int u){
    if(vis[u])
        return;
    vis[u] = 1;
    for (int i = 0, cnt = 1; i < g[u].size() - 1; i++){
        if(g[u][i] == g[u][i+1])
            cnt++;
        else{
            if(cnt == 1){
                put(u, g[u][i]);
                dfs(g[u][i]);
            }
            cnt = 1;
        }
    }
}
map<pair<int, int>, int> mp, mp2;
vector<int> vv[maxn * 10];
void topu(){
    queue<int> Q;
    int ans = 0;
    for (int i = 1; i <= n; i++){
        mp2[{min(p[i], p[i % n + 1]), max(p[i], p[i % n + 1])}] = 1;
    }
    for (int i = 1; i <= m; i++){
        vis[i] = 0;
    }
    for (int i = 1; i <= m; i++){
        e[i].cnt += mp2[{e[i].a, e[i].b}];
        e[i].cnt += mp2[{e[i].b, e[i].c}];
        e[i].cnt += mp2[{e[i].a, e[i].c}];
        if(e[i].cnt == 2)
            Q.push(i);
    }
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        q[++ans] = u;
        vis[u] = 1;
        pair<int, int> pa;
        if(!mp2[{e[u].a, e[u].b}])
            pa = {e[u].a, e[u].b};
        if(!mp2[{e[u].b, e[u].c}])
            pa = {e[u].b, e[u].c};
        if(!mp2[{e[u].a, e[u].c}])
            pa = {e[u].a, e[u].c};
        mp2[{pa.first, pa.second}] = 1;
        for(auto t : vv[mp[{pa.first, pa.second}]]){
            e[t].cnt++;
            if(e[t].cnt == 2)
                Q.push(t);
        }
    }
    if(n == 3)
        q[++ans] = 1;
}

void solve(){
    cin >> n;
    tot = 0;
    mp.clear();
    mp2.clear();
    for (int i = 1; i <= n; i++){
        g[i].clear();
        vv[i].clear();
        p[i] = q[i] = vis[i] = pos[i] = 0;
    }
    for (int i = 1; i <= n - 2; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a > b)
            swap(a, b);
        if(a > c)
            swap(a, c);
        if(b > c)
            swap(b, c);
        g[a].push_back(b);
        g[a].push_back(c);
        g[b].push_back(a);
        g[b].push_back(c);
        g[c].push_back(a);
        g[c].push_back(b);

        if(!mp.count({a, b})){
            mp[{a, b}] = ++tot;
            vv[tot].clear();
        }
        if(!mp.count({a, c})){
            mp[{a, c}] = ++tot;
            vv[tot].clear();
        }
        if(!mp.count({b, c})){
            mp[{b, c}] = ++ tot;
            vv[tot].clear();
        }
        vv[mp[{a, b}]].push_back(i);
        vv[mp[{a, c}]].push_back(i);
        vv[mp[{b, c}]].push_back(i);
        e[i] = {a, b, c, 0};
    }
    for (int i = 1; i <= n; i++){
        g[i].push_back(n + 1);
        sort(g[i].begin(), g[i].end());
        
    }
    pos[1] = p[1] = 1;
    m = n - 2;
    dfs(1);
    topu();
    for (int i = 1; i <= n; i++)
        cout << p[i] << " ";
    cout << endl;
    for (int i = 1; i <= m; i++){
        cout << q[i] << " ";
    }
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    freopen("Ein.txt", "r", stdin);
    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}