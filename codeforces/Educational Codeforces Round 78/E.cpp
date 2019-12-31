#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
vector<int> G[maxn];
int l[maxn], r[maxn];
int cnt;
set<int> st;
void dfs(int u, int fa){
    int len = G[u].size();
    for (int i = 0; i < len; i++){
        int v = G[u][i];
        if(v == fa)
            continue;
        r[v] = --cnt;
    }
    l[u] = --cnt;
    for (int i = len - 1; i >= 0; i--){
        int v = G[u][i];
        if(v == fa)
            continue;
        dfs(v, u);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i<n; i++){
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    r[1] = 2 * n;
    cnt = 2 * n;
    for (int i = 2 * n - 1; i >= 1; i--)
        st.insert(i);
    dfs(1, 1);
    for (int i = 1; i <= n; i++){
        cout << l[i] << " " << r[i] << endl;
    }
    return 0;
}