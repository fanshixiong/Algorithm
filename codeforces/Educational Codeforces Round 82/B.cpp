#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;

void solve(){
    ll n, g, b;
    cin >> n >> g >> b;
    ll m = (n + 1) >> 1;
    ll t = g + b, ans = ((m - 1) / g) * t;
    if(m % g == 0)
        ans += g;
    else
        ans += (m % g);
    
    cout << max(ans, n) << endl;
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