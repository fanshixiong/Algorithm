#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll md = 1e18;
ll a[maxn];
void solve(){
    int n; cin >> n;
    ll ans = 1;
    bool flg = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 0) flg = 1;
    }
    if(flg){
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < n; i++){
        ans *= a[i];
        if(ans > md){ ans = -1; break;}
    }
    cout << ans << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}