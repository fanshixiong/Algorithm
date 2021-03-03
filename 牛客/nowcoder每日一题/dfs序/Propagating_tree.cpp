/*
https://ac.nowcoder.com/acm/problem/110318
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 10;

int l[maxn], r[maxn];
int bits[maxn];
vector<int> G[maxn];
int n, m, k, cnt = 0;
int a[maxn], dep[maxn];

int lowbit(int x){
    return x & (-x);
}
void add(int x, int val){
    while(x < maxn){
        bits[x] += val;
        x += lowbit(x);
    }
}
int query(int x){
    int res = 0;
    while(x){
        res += bits[x];
        x -= lowbit(x);
    }
    return res;
}

void dfs(int u, int fa){
    l[u] = ++cnt;
    dep[u] = dep[fa] + 1;
    for(auto v : G[u]){
        if(v == fa) continue;
        dfs(v, u);
    }
    r[u] = cnt;
}


int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    
    dfs(1, 0);
    // for(int i = 1; i <= n; i++) add(l[i], a[i]);
    for(int i = 0; i < m; i++){
        int op; cin >> op;
        if(op == 1){
            int x, y; cin >> x >> y;
            if(dep[x] & 1){
                add(l[x], y);
                add(r[x] + 1, -y);
            } else {
                add(l[x], -y);
                add(r[x] + 1, y);
            }
        }
        else{
            int x; cin >> x;
            int y = query(l[x]);
            if(dep[x] & 1) cout << a[x] + y << endl;
            else cout << a[x] - y << endl;
        }
    }
    return 0;
}