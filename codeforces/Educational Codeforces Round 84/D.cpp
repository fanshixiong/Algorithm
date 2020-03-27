#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int q[maxn], p[maxn], c[maxn], vis[maxn];

int func(int cnt){
    for (int i = 1; i <= cnt; i++){
        if(cnt % i != 0) continue;
        for (int j = 0; j < i; j ++){
            int t = q[j];
            for (int x = j; x < cnt; x += i){
                if(q[x] != t) t = 0;
            }
            if(t) return i;
        }
    }
    return -1;
}
void solve(){
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> c[i];
    }
    for (int i = 0; i <= n; i++){
        vis[i] = 0;
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++){
        if(vis[i]) continue;
        int cnt = 0, t = i;
        while(!vis[t]){
            q[cnt++] = c[t];
            vis[t] = 1;
            t = p[t];
        }
        ans = min(ans, func(cnt));
    }
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}