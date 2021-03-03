/*
https://ac.nowcoder.com/acm/problem/204871
*/
/*
https://ac.nowcoder.com/acm/problem/23051

https://blog.nowcoder.net/n/0055f19c0e49422786d7b7981a914709
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
    for(auto v : G[u]){
        if(v == fa) continue;
        dfs(v, u);
    }
    r[u] = cnt;
}

int a[maxn], op[maxn], b[maxn], val[maxn];

int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(k, 0);
    for(int i = 1; i <= n; i++) add(l[i], a[i]);
    for(int i = 0; i < m; i++){
        int op; cin >> op;
        if(op == 1){
            int x, y; cin >> x >> y;
            add(l[x], y);
        }
        else{
            int x; cin >> x;
            cout << (query(r[x]) - query(l[x]-1)) << endl;
        }
    }
    return 0;
}