# codeforces 1326 E.Bombs

#### 题意：

给定$[1,n]$的排列*p*,*q*，将$p_i$依次加入初始为空的集合*S*，$q_i$的值表示第*i*次加入的值为bomb。若加入的是bomb就把当前集合最大值从集合中移出(先加再移出)。现在规定对于每一个*i*，$q_1...q_{i-1}$都是bomb。求对于每一个$i∈[1,n]$每次操作后集合中的最大值。

#### 题解：

1. 首先bomb越多，最大值一定不会变的更大，所以该序列一定为非递增序列。
2. 用线段树维护一下每个节点**右侧炸弹的个数 - 右侧大于 x 的数**的个数 ，显然对于每个节点而言，如果这个值大于等于 0 的话，那么 x + 1 及以上的答案是肯定不可能的，因为全都被炸弹炸没了，我们就可以用一个 while 维护符合条件的答案了，又因为我们需要所有的答案都大于等于 0 时才满足条件，所以我们只需要维护一下区间最小值就好了，最小值如果大于等于 0 的话，那么就说明所有节点都满足这个条件了。

代码：

```cpp
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
```

