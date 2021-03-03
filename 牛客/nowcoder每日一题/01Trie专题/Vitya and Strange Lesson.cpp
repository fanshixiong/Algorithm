/*
https://ac.nowcoder.com/acm/problem/112209
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 6e6 + 10;
int read(){ int x; scanf("%d", &x); return x;}
int sz[maxn], ch[maxn][2];
int size = 1, rt = 1;
int n, m, last;

void insert(int u, int t, int x){
    if(t < 0){sz[u] = 1; return;}
    int i = (x >> t) & 1;
    if(!ch[u][i]) ch[u][i] = ++size;
    insert(ch[u][i], t - 1, x);
    sz[u] = sz[ch[u][i]] + sz[ch[u][!i]];
}
int query(int u, int t, int x){
    if(t < 0 || u == 0) return 0;
    int i = (x >> t) & 1;
    if((1 << t) != sz[ch[u][i]]) return query(ch[u][i], t - 1, x);
    else return query(ch[u][!i], t - 1, x) + (1 << t);
}

int main(){
    n = read(); m = read(); 
    for(int i = 1; i <= n; i++) insert(rt, 20, read());
    while(m--){
        last ^= read();
        printf("%d\n", query(rt, 20, last));
    }
    return 0;
}