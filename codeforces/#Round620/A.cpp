#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;

void solve(){
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll t = (y - x) / (a + b);
    if(x+a*t != y-b*t)
        cout << -1 << endl;
    else
        cout << t << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}