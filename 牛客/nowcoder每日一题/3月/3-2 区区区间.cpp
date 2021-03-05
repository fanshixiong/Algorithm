#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1e9+7;
ll m, n, k;
int a[maxn];
ll sum[maxn << 2], lazy[maxn << 2];
ll calc(ll x, ll n){
    return (x + x + n - 1) * n / 2;
}
void push_up(int rt){
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void push_down(int rt, int l, int r){
    if(lazy[rt]){
        int mid = (l + r) >> 1;
        lazy[rt << 1] = lazy[rt], lazy[rt << 1 | 1] = lazy[rt] + (mid - l + 1);
        sum[rt << 1] = calc(lazy[rt << 1], mid - l + 1); 
        sum[rt << 1 | 1] = calc(lazy[rt << 1 | 1], r - mid); 
        lazy[rt] = 0;
    }
}
void update(int rt, int l, int r, int L, int R, int k){
    if(L <= l && r <= R){
        ll x = k + l - L, n = r - l + 1;
        lazy[rt] = x;
        sum[rt] = calc(x, n);
        return;
    }
    push_down(rt, l, r);
    int mid = (l + r) >> 1;
    if(L <= mid) update(rt << 1, l, mid, L, R, k);
    if(mid < R) update(rt << 1 | 1, mid + 1, r, L, R, k);
    push_up(rt);
}
ll query(int rt, int l, int r, int L, int R){
    if(L <= l && r <= R) return sum[rt];
    push_down(rt, l, r);
    ll res = 0;
    int mid = (l + r) >> 1;
    if(L <= mid) res += query(rt << 1, l, mid, L, R);
    if(mid < R) res += query(rt << 1 | 1, mid + 1, r, L, R);
    return res;
}
void build(int rt, int l, int r){
    if(l == r) {
        sum[rt] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(m--){
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1){
            cin >> k;
            update(1, 1, n, l, r, k);
        }
        else{
            cout << query(1, 1, n, l, r) << endl;;
        }
    }
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}