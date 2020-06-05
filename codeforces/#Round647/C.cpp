#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int n, x; cin >> n >> x;
    int degred[n + 1];
    memset(degred, 0, sizeof degred);
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        degred[u]++; degred[v]++;
    }
    if(degred[x] <= 1){
        cout << "Ayush" << endl;
        return;
    }
    if(n % 2 == 0) cout << "Ayush" << endl;
    else cout << "Ashish" << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}