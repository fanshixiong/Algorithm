#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int n, m, k; cin >> n >> m >> k;
    int t = n / k;
    if(m <= t) cout << m << endl;
    else if(m >= n) cout << 0 << endl;
    else {
        cout << t -  (m-t + k - 2) / (k-1) << endl;
    }
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}