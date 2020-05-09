#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn], f[maxn];
void solve(){
    int n; cin >> n;
    memset(f, 0, sizeof f);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) f[((i + a[i % n]) % n + n ) % n]++;
    bool flg = true;
    for (int i = 0; i < n; i++){
        if(f[i] != 1) flg = false;
    }
    if (flg) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}