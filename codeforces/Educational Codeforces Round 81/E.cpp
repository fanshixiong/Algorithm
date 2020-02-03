#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5 + 10;

struct node{
    int l, r;
    ll laze, val;
} segment_tree[maxn << 2];

int n, p[maxn], id[maxn];
ll a[maxn], sum[maxn];

void push_Up(int rt){
    segment_tree[rt].val = min(segment_tree[rt << 1].val, segment_tree[rt << 1 | 1].val);
}

void build(int rt, int l, int r){
    segment_tree[rt].l = l;
    segment_tree[rt].r = r;
    if (l == r){
        segment_tree[rt].val = sum[l];
        segment_tree[rt].laze = 0ll;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_Up(rt);
}

void push_Down(int rt){
    segment_tree[rt << 1 | 1].val += segment_tree[rt].laze;
    segment_tree[rt << 1 | 1].laze += segment_tree[rt].laze;
    segment_tree[rt << 1].val += segment_tree[rt].laze;
    segment_tree[rt << 1].laze += segment_tree[rt].laze;
    segment_tree[rt].laze = 0;
}

void update(int rt, int l, int r, int num){
    if(segment_tree[rt].laze && l != r)
        push_Down(rt);
    if(segment_tree[rt].l >= l && segment_tree[rt].r <= r){
        segment_tree[rt].val += num;
        segment_tree[rt].laze += num;
        return;
    }
    int mid = segment_tree[rt].l + segment_tree[rt].r >> 1;
    if(r > mid){
        update(rt << 1 | 1, l, r, num);
    }
    if(l <= mid){
        update(rt << 1, l, r, num);
    }
    push_Up(rt);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> p[i];
        id[p[i]] = i;
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    ll ans = a[n];
    build(1, 1, n - 1);
    ans = min(ans, segment_tree[1].val);
    int x;
    for (int i = 1; i <= n; i++){
        x = id[i];
        if(x != n){
            update(1, x, n - 1, -a[x]);
        }
        if(x != 1){
            update(1, 1, x - 1, a[x]);
        }
        ans = min(ans, segment_tree[1].val);
        //cout << ans << "  ";
    }
    cout << ans << endl;
    return 0;
}