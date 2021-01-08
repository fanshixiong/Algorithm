/*
https://ac.nowcoder.com/discuss/586195
数学 容斥
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];
ll L, R, k;

bool isPrime(ll n){
    for(ll i = ; i <= n / i; i++){
        if(n % i == 0) return false;
    }
    return true;
}
ll calc(ll n, ll m){
    if(!isPrime(m)) return 0;
    if(n <= m) return (n == m);

    ll ans = n / m;
    for(ll i = 2; i < m && i <= n / m; i++){
        ans -= calc(n / m, i);
    }
    return ans;
}
void solve(){
   cin >> L >> R >> k;
   cout << calc(R, k) - calc(L-1, k) << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
/*
1 80 7
*/