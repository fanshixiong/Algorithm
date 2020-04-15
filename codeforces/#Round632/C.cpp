#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    ll n; cin >> n;
    map<ll, int> p;
    p[0] = 0;
    ll sum = 0, ans = 0;
    int previs = -1;
    for (int i = 1; i <= n; i++){
        ll x; cin >> x;
        sum += x;
        if(p.count(sum)) previs = max(previs, p[sum]);
        ans += i - previs - 1;
        p[sum] = i;
    }
    cout << ans << endl;
}
int main(){
    IOS;
    int t; t = 1;
    while(t--){
        solve();
    }
    return 0;
}