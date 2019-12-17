#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353;
const int maxn = 2e5+10;
ll dp[maxn];
ll pow(ll a, ll b){
    ll res=1;
    while(b){
        if(b&1){
            res = (res*a) % mod;
        }
        a = (a*a) % mod;
        b >>= 1;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        ll x;
        cin >> x;
        ll p = 100 * pow(x, mod-2) % mod;
        dp[i] = (dp[i-1]+1)*p%mod;
    }
    cout << dp[n] << endl;
    return 0;
}