/*
https://ac.nowcoder.com/acm/problem/112932
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;

int a[maxn], cnt = 0;
int l[maxn], r[maxn];
vector<int> G[maxn];

void dfs(int u, int fa){
    l[u] = ++cnt;
    a[cnt] = u;
    for(auto v : G[u]) {
        if(fa == v) continue;
        dfs(v, u);
    }
    r[u] = cnt;
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 2; i <= n; i++) {
        int u; cin >> u;
        G[i].push_back(u);
        G[u].push_back(i);
    }
    dfs(1, 0);
    for(int i = 1; i <= q; i++){
        int u, k;
        cin >> u >> k;
        if(l[u] + k - 1 > r[u]) cout << -1 << endl;
        else cout << a[l[u] + k - 1] << endl;
    }
    return 0;
}