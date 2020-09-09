#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
vector<int> G[maxn];
int dist; //a b距离
int n, a, b, da, db;
int max_len, p;
void dfs(int u, int fa, int d){
    if(d > max_len){
        max_len = d;
        p = u;
    }
    if(u == b && !dist) dist = d;  

    for(auto v:G[u]){
        if(v == fa) continue;
        dfs(v, u, d+1);
    }
}
int maxLength(){
    max_len = -1;
    p = 0;
    dfs(a, -1, 0);
    dfs(p, -1, 0);
    return max_len;
}
void solve(){
    cin >> n >> a >> b >> da >> db;
    for (int i = 0; i <= n; i++) G[i].clear();

    for (int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dist = 0;
    int len = maxLength();
    if (da >= (len + 1) / 2 || da >= dist || da * 2 + 1 > db /*代表a把b追到死胡同的时候，b需要反向跑，
    不存在A只差一步追上B的时候，B可以反向再跑一段很长的距离，使得A一步追不上B。*/) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}