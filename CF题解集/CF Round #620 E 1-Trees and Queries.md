## CF Round #620 E [1-Trees and Queries](https://codeforces.com/contest/1304/problem/E)

---



题意：给你一颗树，进行$q$次查询，每次查询时在树上加一条边，然后问此时两点间的距离能否为一个特定的值$k$，（能反复经过同一个节点或同一条边）。

基本思路：加了一条边连接了x，y​以后，a，b两点间的距离就有三种形式，即 $dist(a,b) , dist(a,x) + dist(y,b) +1 ,dist(a,y) +dist(x,b) +1$;然后由于能反复经过同一个节点或同一条边，所以答案一定是上面三种可能 + $2 * k $(k为任意自然数)，所以直接循环判断就行，我这里是奇偶形式判断（不如直接循环）。
主要知识上的难点为通过lca快速求树上两点间的距离，可以直接套模板。



```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;
int n, q;
vector<int> G[maxn];
int fa[maxn][21], depth[maxn];


void dfs(int u, int f){
    fa[u][0] = f;
    for (int i = 1; i <= 20; i++){
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(f != v){
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}
int lca(int x, int y){
    int u = x, v = y;
    if(depth[u] < depth[v])
        swap(u, v);
    for (int i = 20; i >= 0; i--){
        if(depth[fa[u][i]] >= depth[v]){
            u = fa[u][i];
        }
    }
    if(u == v)   return abs(depth[x] - depth[y]);
    for (int i = 20; i >= 0; i--){
        //if(depth[fa[u][i]] != depth[fa[v][i]]){ //为啥我也不知道...
        if(fa[u][i] != fa[v][i]){
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return depth[x] + depth[y] - 2 * depth[fa[u][0]];
}
bool check(int x, int y){
    return (y>=x) && (x & 1) == (y & 1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    depth[0] = 0;
    dfs(1, 0);
    cin >> q;
    while(q--){
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        if(check(lca(a, b), k) || check(lca(a, x)+lca(y, b) + 1, k) || check(lca(a, y) + lca(x, b) + 1, k)){
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
```



---



参考：

1. [[RMQ算法](https://www.cnblogs.com/fans-fan/articles/12341604.html)]

2. [[最近公共祖先：LCA及其用倍增实现](https://www.cnblogs.com/fans-fan/articles/12341948.html)]