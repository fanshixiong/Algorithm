#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;
int a[maxn], p[maxn], vis[maxn];
void solve(){
    memset(vis, 0, sizeof(vis));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> p[i];
        vis[p[i]] = 1;
    }
    if(m == n-1){
        cout << "YES" <<endl;
        return;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n - i; j++){
            if(a[j] > a[j+1]){
                if(!vis[j]){
                    cout << "NO" << endl;
                    return;
                }
                swap(a[j], a[j + 1]);
            }
        }
    }
    cout << "YES" << endl;
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