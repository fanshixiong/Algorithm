#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e6 + 10;
int a[maxn], p[maxn], ans[maxn];
vector<int> G[maxn];
bool cmp(int x, int y){
    return a[x] < a[y];
}
void solve(){
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) p[i] = i, cin >> a[i];
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++){
        int u = p[i]; //待求的点
        int val = a[u];  //待求的点的期望的值
        set<int> s;
        for(auto x : G[u]){ //将已填好值的点加进去
            if(ans[x])  s.insert(ans[x]);
        }

        if(s.size() != val-1){cout << -1 << endl; return;}
        int cnt = 1;
        for(auto x : s){
            if(cnt != x){cout << -1 << endl; return;}
            cnt++;
        }
        ans[u] = a[u];
    }
    for (int i = 1; i <= n; i++) cout << p[i] << " ";
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}