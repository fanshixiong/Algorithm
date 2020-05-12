/*
我们可以这么想， k对相邻的颜色相同， 那么剩下的n-k个格子中其中有一个格子可以取m中，其它的只能取m-1中， 因为，n-k格子一定不能与左边或右边的颜色一样。所以有

所以答案就是 

https://zhuanlan.zhihu.com/p/139779679
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const int mod = 998244353;
ll f[maxn];

ll ksm(ll a, int n){
    ll ans = 1;
    while(n){
        if(n & 1)ans = (ans * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans;
}
void solve(){
    ll n, m, k; cin >> n >> m >> k;
    ll ans = 0;
    f[0] = 1;
    ll base = 1, cnt = 1;
    for (int i = 1; i < n; i++){
        base = (base * (n - i)) % mod;
        cnt = (cnt * i) % mod;
        f[i] = base * ksm(cnt, mod - 2) % mod;
    }

    for (int i = 0; i <= k; i++){
        ans += (m % mod * ksm(m - 1, n - i - 1)) % mod * f[i];
        ans %= mod;
    }
    cout << ans << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}