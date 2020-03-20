# CodeForces - 1321E World of Darkraft: Battle for Azathoth



**题目大意：**给出 n 个武器及花费，m 个防具及花费，以及 k 个怪物及属性，每个怪物的属性同样有着攻击力，防御力以及价值，初始时可以选择一个武器以及一个防具，如果此时的攻击力大于怪物的攻击力，且防御力大于怪物的防御力，则可以打败这个怪物，并且获得其掉落的价值，现在问如何挑选初始时的武器可以使得收益最大化

**题目分析：**二维偏序的好题，补题的时候看到标签上写着数据结构，双指针和排序，以及这个题目攻击力和防御力的攻击范围都才$1e^6$而不是$1e^9$，加上对于每个怪物是否击败都有着两个维度的限制，所以不难想到要用二维偏序来解决，先对攻击力排序，这样就能忽略掉攻击力带来的限制了，因为题目的数据范围都在$1e^6$以内，所以我们在读入时将其映射到数轴上，而不是开一个二维数组保存，这样就相当于对攻击力进行桶排序了，可以优化掉快速排序 $logn$ 的时间复杂度，最后每个怪物的属性还是需要开一个三个变量的结构体保存，想一下如何将防御力映射到线段树上去，因为击败某个怪物的条件是攻击力以及防御力都必须严格大于该怪物，而对攻击力排序已经可以忽略掉攻击力带来的影响了，剩下的我们可以将线段树的每个端点视为防御力的具体数值，而每个端点所保存的数值是利润，若要查询最终答案，只需要查询一下每次线段树中的最大值，再减去当前遍历到的武器的花费就是答案了，至于更新线段树也是比较好想的，因为对于某个怪物的防御力而言，只有大于其防御力的防具才能够打败这个怪物，那么只需要对区间$[ x + 1 , n ]$都加上这个怪物的价值就好了，其中 x 为这个怪物的防御力，线段树初始化为每点防御力的价格，因为在将防御力映射到数轴上之后，会有很多地方的花费是 0 ，但并不代表此时的花费为 0 ，所以需要预处理一下，如果某个点的花费为 0 ，那么这个点可能会被比这个点大的防具所包含，所以倒着维护一下就好了，还有一个小细节就是可能防御力较高的防具花费会比较低，就像样例给出的数据一样，这个时候还需要维护一下最小值

​	还有一些小细节就是，因为题目的数据刚好卡到int，所以数据范围不会爆int，不过在设置无穷小的时候，因为极限情况会到达$-2e^9$，所以要把无穷小设的小一些


```cpp
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
```

