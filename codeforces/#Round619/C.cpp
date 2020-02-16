#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;

void solve(){
    ll n, m;
    cin >> n >> m;
    ll z = n - m, g = m + 1, k = z / g;
    cout << (ll)(n * (n + 1) / 2 - k * (k + 1) / 2 * g - (k + 1) * (z % g)) << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >>t;
    while(t--){
        solve();
    }
    return 0;
}