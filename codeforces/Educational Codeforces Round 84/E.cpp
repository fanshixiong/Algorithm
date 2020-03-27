#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 998244353;
const int maxn = 2e5 + 10;

ll ans[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    ll x = 810;
    ans[1] = 10; ans[2] = 180;
    for (int i = 3; i < maxn; i++){
        ans[i] = (ans[i - 1] * 10 + x) % mod;
        x = (x * 10) % mod;
    }
    for (int i = n; i >= 1; i--){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
