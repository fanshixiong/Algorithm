#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 1e5 + 10;
int a[maxn];
int n, k;
void solve(){
    cin >> n >> k;
    unordered_map<int, bool> vis;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[a[i]] = 1;
    }
    sort(a+1, a+1+n);
    if(a[n] == n-1){
      cout << 1ll * (n + k) << endl; 
      return;
    }
    int p;
    for(int i = 1; i <= n; i++){
        if(a[i] != i-1){p = i-1; break;}
    }
    // cout << p;
    if(vis[(p + a[n] + 1) / 2] || k == 0) cout << n << endl;
    else cout << n + 1 << endl;
}  
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}