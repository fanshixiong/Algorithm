#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int n, m; cin >> n >> m;
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    if(n >= 3) cout << 2 * m << endl;
    else cout << m << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}