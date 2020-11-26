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
int m, cnt = 0;

int lowbit(int x){
    return x & (-x);
}
void add(int x, int val){
    while(x <= cnt + 1){
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

void dfs(int u){
    l[u] = ++cnt;
    for(auto v : G[u]) dfs(v);
    r[u] = cnt;
}

int a[maxn], op[maxn], b[maxn], val[maxn];

int main(){
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> op[i] >> a[i];
        if(op[i] == 2) cin >> b[i];
        else if(op[i] == 1){
            G[a[i]].pb(++cnt);
            b[i] = cnt;
        }
    }
    dfs(0);
    // cout << cnt << endl;
    for(int i = 0; i < m; i++){
        if(op[i] == 1) val[l[b[i]]] -= query(l[a[i]]); 
        else if(op[i] == 2){
            add(l[a[i]], b[i]);
            add(r[a[i]] + 1, -b[i]);
        }
        else cout << val[l[a[i]]] + query(l[a[i]]) << endl; 
    }
    return 0;
}