/*
http://acm.hdu.edu.cn/showproblem.php?pid=4825
*/
#include<bits/stdc++.h>
using namespace std;

int read(){int x; scanf("%d", &x); return x;}

const int maxn = 5e6 + 10;
int ch[maxn][2], value[maxn];
int a[maxn];
int sz = 1, rt = 1;
int m, n, t, T;

void insert(int u, int t, int x, int id){
    if(t < 0) { value[u] = id; return; }
    int i = (x >> t) & 1;
    if(!ch[u][i]) ch[u][i] = ++sz;
    insert(ch[u][i], t - 1, x, id);
}

int query(int u, int t, int x){
    if(t < 0) return value[u];
    int i = (x >> t) & 1;
    if(ch[u][!i]) return query(ch[u][!i], t-1, x);
    return query(ch[u][i], t - 1, x);
}

void solve(){
    n = read(); m = read();
    memset(ch, 0, sizeof ch);
    sz = rt = 1;
    memset(value, 0, sizeof value);
    for(int i = 1; i <= n; i++) a[i] = read(), insert(rt, 31, a[i], i);

    printf("Case #%d:\n", t - 1);
    for (int i = 1; i <= m; i++){
        int s = read();
        printf("%d\n", a[query(rt, 31, s)]);
    }
}

int main(){
    t = 1; T = read();
    while(t++ <= T) solve();
    return 0;
}