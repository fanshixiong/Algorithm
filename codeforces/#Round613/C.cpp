#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+7;
vector<ll> v;
ll ans;

void dfs(ll a, ll b, int x){
    if(x >= v.size()){
        ans = min(ans, max(a, b));
        return;
    }
    dfs(a * v[x], b, x + 1);
    dfs(a, b * v[x], x + 1);
} 
int main(){
    ios_base::sync_with_stdio(0);
    ll x; cin >> x;
    ans = x;
    ll p = x;
    if(x == 1){
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    for (ll i = 2; i * i <= p; i++){
        if(p % i==0){
            ll n = 1;
            while(p%i == 0){
                n *= i;
                p /= i;
            }
            v.push_back(n);
        }
    }
    if(p>1)
        v.push_back(p);
    sort(v.begin(), v.end());
    dfs(1, 1, 0);
    cout << ans << " " << x / ans << endl;
    return 0;
}