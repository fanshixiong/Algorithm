#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int n; cin >> n;
    int lastp = 0, lastc = 0;
    bool flg = true;
    for(int i = 0; i < n; i++){
        int c, p;
        cin >> c >> p;
        if(c < lastc || p < lastp || c < p) flg = false;
        if(c - lastc < p - lastp) flg = false;
        lastc = c;
        lastp = p;
    }
    if(flg) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}