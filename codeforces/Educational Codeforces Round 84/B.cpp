#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int vis[maxn], x[maxn];
void solve(){
    int n; cin >> n;
    for (int i = 0; i <= n; i++){
        vis[i] = x[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int v; cin >> v;
            if (!x[i] && !vis[v]) {
                x[i] = v, vis[v] = 1;
            }
        }
    }
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++){
        if(!x[i]){
            a = i; break;
        }
    }
    for (int i = 1; i <= n; i++){
        if(!vis[i]){
            b = i; break;
        }
    }
    if(a || b){
        cout << "IMPROVE" << endl;
        cout << a << " " << b << endl;
    }
    else{
        cout << "OPTIMAL" << endl;
    }
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