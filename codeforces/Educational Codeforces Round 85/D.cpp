#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
ll n, sum[maxn];
ll calc(ll pos){
    if(pos == (n - 1) * n + 1) return 1;
    int p = lower_bound(sum + 1, sum + 1 + n, pos) - sum;
    int t = pos - sum[p - 1];
    if(t & 1) return p;
    else return p + t / 2;   
}
void solve(){
    cin >> n;
    ll l, r; cin >> l >> r;
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1] + 2 * (n - i);
    }
    for(ll i = l; i <= r; i++){
        cout << calc(i) << " ";
    }
    cout << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}