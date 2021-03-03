#include<bits/stdc++.h>
using namespace std;

const int maxn = 6e6 + 10;
int ch[maxn][2], sz[maxn], val[maxn], cnt[maxn];
int size = 0, rt = 0;
int n, m;

void insert(int u, int t, int x){
    if(t < 0) { val[u] = x; return;}
    int i = (x >> t) & 1;
    if(!ch[u][i])  ch[u][i] = ++size;
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
    if(t < 0) return val[u];
    int i = (x >> t) & 1;
    if(sz[ch[u][!i]]) return query(ch[u][!i], t-1, x);
    else return query(ch[u][i], t-1, x);
}

int main(){
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        char c; cin >> c;
        int t; cin >> t;
        if(c == '+') insert(rt, 30, t);
        else if(c == '-') erase(rt, 30, t);
        else  printf("%d\n", max(t, query(rt, 30, t) ^ t));
    }
    return 0;
}
/*
12
? 1
+ 1
+ 4
? 5
? 6
*/