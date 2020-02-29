#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a[205], vis[205], ans[205];
    memset(vis, 0, sizeof(vis));
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        vis[a[i]] = 1;
        ans[2 * i] = a[i];
    }
    for (int i = 0; i < n; i++){
        bool yes = 0;
        for (int j = 1; j <= 2 * n; j++){
            if(vis[j])continue;
            if(j > ans[2*i]){
                ans[2 * i + 1] = j;
                yes = 1;
                vis[j] = 1;
                break;
            }
        }
        if(!yes){
            cout << -1 << endl;
            return;
        }
    }

    for (int i = 0; i < 2 * n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
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