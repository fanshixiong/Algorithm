#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
ll f[maxn];

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b){
    return a / gcd(a, b) * b ;
}

int n, a, b, q;
ll get(ll x){
    return 1ll * f[n - 1] * (x / n) + 1ll * f[x % n];
}
void solve(){
    cin >> a >> b >> q;
    memset(f, 0, sizeof f);
    n = lcm(a, b);
    for (int i = 0; i < n; i++){
        if(i % a % b != i % b % a) f[i] = 1;
    }
    for (int i = 1; i < n; i++) f[i] += f[i - 1];
    //cout << f[n - 1] << endl;
    while(q--){
        ll l, r;
        cin >> l >> r;
        cout << get(r) - get(l - 1) << " ";
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