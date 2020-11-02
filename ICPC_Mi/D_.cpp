#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1e3 + 7;
vector<int>G[maxn];
vector<int>ans;
int low[maxn],dfn[maxn],cut[maxn],f[maxn],dfs_clock;

void init()
{
    dfs_clock = 0;
    for(int i = 0;i <= 1000;i++)
        G[i].clear();
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    memset(cut,0,sizeof(cut));
    memset(f,0,sizeof(f));
    ans.clear();
}

void add(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}

void tarjan(int u,int fa)
{
    low[u] = dfn[u] = ++dfs_clock;
    int son = 0;
    for(int i = 0;i < G[u].size();i++)
    {
        int v = G[u][i];
        if(!dfn[v])
        {
            son++;
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v] >= dfn[u]) cut[u]++;
        }
        else if(dfn[v] < dfn[u] && v != fa)
            low[u] = min(low[u],dfn[v]);
    }
    if(cut[u] >= 1)
    {
        cut[u]++;
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int u,v;
    int kase = 0,mx = 0;
    init();
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    for(int i = 1;i <= n;i++)
    {
        if(!dfn[i]) tarjan(i, -1);
    }

    for (int i = 1; i <= n; i++){
        printf("%d ", cut[i]);
    }
    return 0;
}

