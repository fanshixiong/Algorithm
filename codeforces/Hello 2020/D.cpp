#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 4e5 + 10;
const int inf = 0x3f3f3f3f;
int n;
struct SegTree{
    int l, r;
    int mx, lazy;
} t[maxn * 4];
struct node{
    int l, r, id;
} a[maxn], b[maxn];
vector<int> l[maxn], r[maxn], alls;

void build(int p, int l, int r){
    t[p].l = l;
    t[p].r = r;
    if(l == r){
        t[p].mx = t[p].lazy = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    t[p].mx = t[p].lazy = 0;
}

void pushdown(int p){
    if(t[p].lazy){
        t[p << 1].mx += t[p].lazy;
        t[p << 1 | 1].mx += t[p].lazy;
        t[p << 1].lazy += t[p].lazy;
        t[p << 1 | 1].lazy += t[p].lazy;
        t[p].lazy = 0;
    }
}

int ask(int p, int l, int r){
    if(t[p].l >= l && t[p].r <= r){
        return t[p].mx;
    }
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    int res = 0;
    if(mid >= l)
        res = max(res, ask(p << 1, l, r));
    if(mid<r)
        res = max(res, ask(p << 1 | 1, l, r));
    return res;
}

void add(int p, int l, int r, int val){
    if(t[p].l >= l && t[p].r <= r){
        t[p].mx += val;
        t[p].lazy += val;
        return;
    }
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    if(mid >= l)
        add(p << 1, l, r, val);
    if(mid<r)
        add(p << 1 | 1, l, r, val);
    t[p].mx = max(t[p << 1].mx, t[p << 1 | 1].mx);
}

bool check(node *a, node *b){
    int len = alls.size();
    build(1, 1, len);
    for (int i = 1; i <= len; i++){
        l[i].clear();
        r[i].clear();
    }
    for (int i = 1; i <= n; i++){
        l[a[i].l].push_back(i);
        r[a[i].r].push_back(i);
    }

    int sz = 0;
    for (int i = 1; i <= len; i++){
        for (int j = 0; j < l[i].size(); j++){
            int id = l[i][j];

            int L = b[id].l, R = b[id].r;

            int res = ask(1, L, R);
            if(res != sz)
                return false;
            add(1, L, R, 1);
            sz++;
        }
        for (int j = 0; j < r[i].size(); j++){
            int id = r[i][j];
            int L = b[id].l, R = b[id].r;
            add(1, L, R, -1);
            sz--;
        }
    }
    return true;
}

int getId(int x){
    return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].l >> a[i].r >> b[i].l >> b[i].r;
        alls.push_back(a[i].l);
        alls.push_back(a[i].r);
        alls.push_back(b[i].l);
        alls.push_back(b[i].r);
        a[i].id = i;
        b[i].id = i;
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    for (int i = 1; i<=n; i++){
        a[i].l = getId(a[i].l);
        a[i].r = getId(a[i].r);
        b[i].l = getId(b[i].l);
        b[i].r = getId(b[i].r);
    }
    int c1 = check(a, b);
    int c2 = check(b, a);
    if(c1 && c2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}