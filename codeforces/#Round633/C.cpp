#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 1e5 + 10;
int a[maxn];
void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int minn = -0x3f3f3f3f, minus = 0x3f3f3f3f;
    for (int i = 0; i < n; i++){
        minn = max(minn, a[i]);
        minus = min(minus, a[i] - minn);
        //cout << minn << " " << minus << endl;
    }
    if(!minus) cout << 0 << endl;
    else cout << (int)log2(-minus) + 1 << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}