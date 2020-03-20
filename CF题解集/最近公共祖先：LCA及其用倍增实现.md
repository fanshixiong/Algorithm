# 最近公共祖先：LCA及其用倍增实现 

 



预处理：

```cpp
int anc[1005][25];
int fa[1005];
vector <int > tree[1005];
int deep[1005];

void dfs(int x)
{
    anc[x][0]=fa[x];
    for (int i=1;i<=22;i++)
    {
        anc[x][i]=anc[anc[x][i-1]][i-1];//anc[x][i]表示离x节点的距离为2的i次方的祖先
    }
    
    for (int i=0;i<tree[x].size();i++)
    {
        if (tree[x][i]!=fa[x])
        {
            int y=tree[x][i];
            fa[y]=x;//记录父亲节点
            deep[y]=deep[x]+1;//记录深度
            dfs(y);
        }
    }
}
```

通过从根节点开始的DFS，我们就预处理好了ANC数组。

下面，我们来考虑如何处理LCA查询。即每次给你两点X和Y，求出它们的LCA(X,Y)。在有了ANC数组之后，求出最近公共祖先就会变得很简单。

首先，让X,Y在同一深度上。在大多数情况下，查询给你的两个点X和Y它们的深度是不同的。但是，如果两点的深度相同，我们就可以实现两个点同时倍增比较何时祖先相同。所以，第一步是使X,Y中深度较深的点往上移动直到与另一个点深度相同。当然，点的移动也可以用倍增完成。

然后，当两点深度相同后，同时向上倍增两个点，当它们祖先刚好相同时，这个祖先就是它们的LCA。

如果你还是有一些不理解的话，不妨看LCA实现的代码：

```cpp
int lca(int x,int y)
{
    if (deep[x]<deep[y]) swap(x,y);//我们希望X是较深的点。

    for (int i=19;i>=0;i--)//这个循环在完成第一步。这里19是可以根据题目修改的
    {
        if (deep[y]<=deep[anc[x][i]])
        {
            x=anc[x][i];
        }
    }
    
    if (x==y) return x;//如果Y是X的祖先，就可以直接返回结果了。
    
    for (int i=19;i>=0;i--)
    {
        if (anc[x][i]!=anc[y][i]) //第二步。
        {
            x=anc[x][i];
            y=anc[y][i];
        }
    }
    
    return anc[x][0];//注意第二步IF语句的条件。
}
```

---



---



实战一下：[poj 1986 Distance Queries](https://www.cnblogs.com/scau20110726/archive/2013/05/27/3102068.html)

---



```cpp
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 3e6+5;
int n,m,k,tot=0;
int fa[N][20],head[N],dis[N],dep[N];
struct man{
    int to,next,w;
}edg[N];
void add(int u,int v,int w){
    edg[tot].to=v;edg[tot].next=head[u];edg[tot].w=w;head[u]=tot++;
}
void dfs(int u,int f){
    fa[u][0]=f;
    for(int i=1;i<20;i++){
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    for(int i=head[u];i!=-1;i=edg[i].next){
        int v=edg[i].to;
        if(v!=f){
            dis[v]=dis[u]+edg[i].w;
            dep[v]=dep[u]+1;
            dfs(v,u);
        }
    }
}
int lca(int u,int v){
    int U=u,V=v;
    if(dep[u]<dep[v])swap(u,v);
    for(int i=19;i>=0;i--){
        if(dep[fa[u][i]]>=dep[v]){
            u=fa[u][i];
        }
    }
    if(u==v)return (abs(dis[U]-dis[V]));
    for(int i=19;i>=0;i--){
        if(fa[u][i]!=fa[v][i]){
            u=fa[u][i];v=fa[v][i];
        }
    }
    return (dis[U]+dis[V]-2*dis[fa[u][0]]);
}
int main(){
    met(head,-1);
    cin >> n >> m;
    string s;
    int u,v,w;
    while(m--){
        cin >> u >> v >> w;
        cin >> s;
        add(u,v,w);add(v,u,w);
    }
    dep[1]=1;
    dfs(1,0);
    cin >> k;
    while(k--){
        cin >> u >> v;
        cout << lca(u,v)) << endl;
    }
    return 0;
}
```

参考：

[1【白话系列】倍增算法](https://blog.csdn.net/JarjingX/article/details/8180560)

[2.【白话系列】最近公共祖先](https://blog.csdn.net/JarjingX/article/details/8183240)

