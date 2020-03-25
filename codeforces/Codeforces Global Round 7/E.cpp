#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 0x3f3f3f3f;
const int N = 3e5 + 100;
int pos[N];
struct Node{
    int l, r, mmin, lazy;
} tree[N << 2];

void build(int k, int l, int r){
    tree[k].l = l;
    tree[k].r = r;
    tree[k].lazy = tree[k].mmin = 0;
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
}

void pushdown(int k){
	if(tree[k].lazy){
        int lz = tree[k].lazy;
        tree[k].lazy = 0;
        tree[k << 1].mmin += lz;
        tree[k << 1].lazy += lz;
        tree[k << 1 | 1].mmin += lz;
        tree[k << 1 | 1].lazy += lz;
    }
}

void pushup(int k){
    tree[k].mmin = min(tree[k << 1].mmin, tree[k << 1 | 1].mmin);
}

void update(int k, int l, int r, int val){
    if(tree[k].l > r || tree[k].r < l)
        return;
	if(tree[k].l >= l&&tree[k].r <= r){
        tree[k].mmin += val;
        tree[k].lazy += val;
        return;
    }
    pushdown(k);
    update(k << 1, l, r, val);
    update(k << 1 | 1, l, r, val);
    pushup(k);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;cin >> n;
    build(1, 1, n);
    for (int i = 1; i <= n; i++){
		int num;cin >> num;
        pos[num] = i;
    }
    int ans = n + 1;
    for (int i = 1; i <= n; i++){
		int q; cin >> q;
		while(tree[1].mmin >= 0){
            ans--;
            update(1, 1, pos[ans], -1);
        }
        cout << ans << " ";
        update(1, 1, q, 1);
    }
    return 0;
}