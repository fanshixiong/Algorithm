#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdio>
#include <chrono>
#include <random>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
#define ls x<<1
#define rs x<<1|1
#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define fun function
#define sz(x) x.size()
#define lowbit(x) x&(-x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const int N=1e6+10;

vector<int>e[N];
int fa[N],dep[N],son[N],siz[N],top[N];

void dfs1(int u,int f) {
    fa[u]=f;
    dep[u]=dep[f]+1;
    siz[u]=1;
    int maxsize=-1;
    for(auto v:e[u]) {
        if(v==f)continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>maxsize) {
            son[u]=v;
            maxsize=siz[v];
        }
    }
}

void dfs2(int u,int t) {
    top[u]=t;
    if(!son[u])
        return ;
    dfs2(son[u],t);
    for(auto v:e[u]) {
        if(v==son[u]||v==fa[u])
            continue;
        dfs2(v,v);
    }
}

int lca(int x,int y) {
    while(top[x]!=top[y]) {
        if(dep[top[x]]<dep[top[y]])    swap(x,y);
        x=fa[top[x]];
    }
    return dep[x]>dep[y]?y:x;
}

int q[N];

bool cmp(int a,int b) {
    return dep[a]>dep[b];
}

int main() {
    IOS;
#ifdef xiaofan
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif

    int n,m;
    cin>>n>>m;
    for(int i=1; i<n; i++) {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs1(1,1);
    dfs2(1,1);

    while(m--) {
        int t;
        cin>>t;
        for(int i=0; i<t; i++) cin>>q[i];
        sort(q,q+t,cmp);
        bool ok=true;
        for(int i=1; i<t; i++) {
            if(dep[q[i]]==dep[q[i-1]]) {
                if(fa[q[i]]!=fa[q[i-1]]) ok=false;
            } else {
                int root=lca(q[i],q[i-1]);
                cout << q[i] << " " << root << " " << fa[q[i]] << endl;
                if(root!=fa[q[i]] && root!=q[i]) ok=false;

            }
        }
        cout<<(ok?"YES":"NO")<<'\n';
    }




    return 0;
}
/*
10 6
1 2
1 3
1 4
2 5
2 6
3 7
7 8
7 9
9 10
4 3 8 9 10
8 7 7
3 3 1
3 2 4 6
YES
2 2 1
3 2 1 5
YES
2 2 1
1 1 1
3 4 8 2
YES
4 1 1
2 6 10
YES
6 1 2
3 5 4 7
NO
4 1 1
NO
*/