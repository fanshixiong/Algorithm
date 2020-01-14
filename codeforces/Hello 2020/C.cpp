#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+7;
ll p[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    ll n, m, ans=0;
    cin >> n >> m;
    p[0] = 1;
    for (ll i = 1; i <= n; i++)
        p[i] = p[i - 1] * i % m;
    for (ll i = 1; i <= n; i++){
        ans = (ans + (1ll * (n-i+1) * p[i] % m * p[n-i+1] % m)) % m;
    }
    cout << ans << endl;
    return 0;
}