#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int maxn = 2e5 + 10;
int n, m, p;
int lazy[maxn << 2], tree[maxn << 2];
struct node{
    int ability, cost;
    node(){}
    node(int a, int c):ability(a), cost(c){}
    bool operator <(node a) const{
        return ability < a.ability;
    }
}a[maxn], b[maxn];
struct monster{
    int defend, attack, gain;
    monster(){}
    monster(int d, int a, int g):defend(d), attack(a), gain(g){}
    bool operator < (monster a)const{
        return defend < a.defend;
    }
} c[maxn];

void pushUp(int node){
    tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
}
void build(int node, int l, int r){
    if(l == r){
        tree[node] = -b[l].cost;
        return;
    }
    int mid = (l + r) >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    pushUp(node);
}
void pushDown(int node){
    if(lazy[node]){
        tree[node << 1] += lazy[node];
        tree[node << 1 | 1] += lazy[node];
        lazy[node << 1] += lazy[node];
        lazy[node << 1 | 1] += lazy[node];
        lazy[node] = 0;
    }
}
void update(int node, int l, int r, int x, int y, int k){
    if(x <= l && y >= r){
        tree[node] += k;
        lazy[node] += k;
        return;
    }
    pushDown(node);
    int mid = (l + r) >> 1;
    if(x <= mid)
        update(node << 1, l, mid, x, y, k);
    if(y > mid)
        update(node << 1 | 1, mid + 1, r, x, y, k);
    pushUp(node);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++){
        cin >> a[i].ability >> a[i].cost;
    }
    for (int i = 1; i <= m; i++){
        cin >> b[i].ability >> b[i].cost;
    }
    for (int i = 1; i <= p; i++){
        cin >> c[i].defend >> c[i].attack >> c[i].gain;
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    sort(c + 1, c + 1 + p);
    build(1, 1, m);
    int now = 1, ans = -0x7fffffff;
    for (int i = 1; i <= n; i++){
        while(now <= p && c[now].defend < a[i].ability){
            int index = upper_bound(b + 1, b + 1 + m, node(c[now].attack, 0)) - b;
            if(index <= m){
                update(1, 1, m, index, m, c[now].gain);
            }
            now++;
        }
        ans = max(ans, tree[1] - a[i].cost);
    }
    cout << ans << endl;    
    return 0;
}