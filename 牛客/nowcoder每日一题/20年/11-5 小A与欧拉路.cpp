/*
https://ac.nowcoder.com/acm/problem/22618

求树直径
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
vector<pi> G[maxn];
int rt1, rt2, fa[maxn], dis[maxn], wi[maxn];

void dfs(int u, int f, int &rt){
    for (auto p : G[u]){
        int v = p.first, w = p.second;
        if(v == f) continue;

        dis[v] = dis[u] + w;
        fa[v] = u; wi[v] = w; //没写出来
        if(dis[v] > dis[rt]) rt = v;

        dfs(v, u, rt);
    }
}
void solve(){
    int n; cin >> n;
    ll ans = 0;
    for(int i = 1; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
        ans += 2 * c;
    }

    dfs(1, 0, rt1);
    dis[rt1] = 0;
    dfs(rt1, 0, rt2);

    while(rt1 != rt2){
        ans -= wi[rt2];
        rt2 = fa[rt2];
    }

    cout << ans << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}