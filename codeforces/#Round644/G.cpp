#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if(n * a != m * b){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int l = 1, r = a;
    for (int i = 1; i <= n; i++){
        bool rev = 0;
        if(l > m) l-=m;
        if(r > m) r-=m;
        if(l > r) rev = 1;
        for (int j = 1; j <= m; j++){
            if(rev){
                if(j >= 1 && j <= r) cout << 1;
                else if(j >= l) cout << 1;
                else cout << 0;
            }else{
                if(j >= l && j <= r) cout << 1;
                else cout << 0;
            }
        }
        cout << endl;
        l += a; r += a;
    }
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}