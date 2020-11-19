#include<bits/stdc++.h>
using namespace std;

int read(){int x; scanf("%d", &x); return x;}

const int maxn = 6e6 + 10;
int ch[maxn][2], sz[maxn];
int size = 0, rt = 0;
int n, m;
int a[maxn], b[maxn], c[maxn];

void insert(int u, int t, int x){
    if(t < 0) return;
    int i = (x >> t) & 1;
    if(!ch[u][i])  ch[u][i] = ++size;;
    sz[ch[u][i]]++;
    insert(ch[u][i], t - 1, x);
}

void erase(int u, int t, int x){
    if(t < 0) return;
    int i = (x >> t) & 1;
    sz[ch[u][i]]--;
    erase(ch[u][i], t - 1, x);
}

int query(int u, int t, int x){
    if(t < 0) return 0;
    int i = (x >> t) & 1;
    if(sz[ch[u][i]]) return query(ch[u][i], t-1, x) + (i << t);
    else return query(ch[u][!i], t-1, x) + ((!i) << t);
}
int main(){
    n = read(); 
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = 1; i <= n; i++) b[i] = read(), insert(rt, 30, b[i]);

    for(int i = 1; i <= n; i++){
        int x = query(rt, 30, a[i]);
        printf("%d\n", a[i] ^ x);
        erase(rt, 30, x);
    }
    return 0;
}