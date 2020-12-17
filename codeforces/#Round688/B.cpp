#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int c[maxn];
void solve(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> c[i];

    int res = 0x3f3f3f3f;
    for (int maxp = 1; maxp <= 100; maxp++){
        int ans = 0, i = 1;
        while(i <= n && c[i] == maxp) i++;
        while(i <= n){
            ans++;
            i += k;
            while(i <= n && c[i] == maxp) i++;
        }
        res = min(res, ans);
    }
    cout << res << endl;
}  
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}