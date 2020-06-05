#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];
void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    int odds = 0, evens = 0;
    for (int i = 0; i < n; i++){
        if(a[i] % 2) odds ++;
        else evens++;
    }
    bool ok = 0;
    for(int i = 1; i <= odds; i++) {
        if (i & 1 && i <= m & m - i <= evens) ok = true;
    }
    cout << (ok ? "Yes" : "No") << '\n';
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}