#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 300;
int a[maxn], vis[maxn];
void solve(){
    memset(vis, 0, sizeof(vis));
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        vis[a[i]]++;
    }
    int cnt = 0;
    for (int i = 1; i < 220; i++){
        if(!vis[i]){
            cnt++;
        }
        if(cnt > x){
            cout << i - 1 << endl;
            return;
        }
    }
}
int main(){
    IOS;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}