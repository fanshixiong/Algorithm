/*
https://ac.nowcoder.com/acm/problem/50993
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 100;
int ch[maxn][2];

int sz = 0, rt, n;

int read() {int x; scanf("%d", &x); return x;}

void insert(int u, int t, int x){
    if(t < 0) return;
    int f = ((x >> t) & 1);
    if(!ch[u][f]) ch[u][f] = ++sz;
    insert(ch[u][f], t-1, x);
}

int ask(int u, int t, int x){
    if(t < 0) return 0;
    int f = ((x >> t) & 1);
    if(ch[u][!f]) return ask(ch[u][!f], t-1, x) + (1 << t);
    
    return ask(ch[u][f], t-1, x);
}

int main(){
    n = read();
    int ans = 0;
    rt = ++ sz;
    for(int i = 0; i < n; i++){
        int x = read();
        insert(rt, 30, x);
        if(i != 0) ans = max(ans, ask(rt, 30, x));
    }
    printf("%d\n", ans);
    return 0;
}