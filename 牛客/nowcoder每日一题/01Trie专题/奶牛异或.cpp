/*
https://ac.nowcoder.com/acm/problem/22998
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e7 + 100;
int ch[maxn][2], id[maxn], a[maxn];

int sz = 0, rt, n;
int ans1, ans2 = 1, ans3 = 1;

int read() {int x; scanf("%d", &x); return x;}

void insert(int u, int t, int x, int ID){
    if(t < 0){ id[u] = ID; return; }
    int f = ((x >> t) & 1);
    if(!ch[u][f]) ch[u][f] = ++sz;
    insert(ch[u][f], t-1, x, ID);
}

int ask(int u, int t, int x){
    if(t < 0) return id[u];
    int f = ((x >> t) & 1);
    if(ch[u][!f]) return ask(ch[u][!f], t-1, x);
    
    return ask(ch[u][f], t-1, x);
}

int main(){
    n = read(); a[0] = 0;
    for(int i = 1; i <= n; i++) (a[i] = a[i-1] ^ read());
    rt = ++ sz;
    for(int i = 1; i <= n; i++){
        insert(rt, 22, a[i-1], i);
        int x = ask(rt, 22, a[i]) - 1;
        if(ans1 < (a[x] ^ a[i])){
            ans1 = (a[x] ^ a[i]);
            ans2 = x + 1;
            ans3 = i;
        }
    }
    printf("%d %d %d\n", ans1, ans2, ans3);
    return 0;
}