#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int p[maxn];
void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = n - 1; i >= 0; i--) cout << p[i] << " ";
    cout << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}