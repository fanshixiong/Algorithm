#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    map<ll, ll> m;
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        m[x - i] += x;
    }
    ll ans = -0x3f3f3f3f;
    for (int i = -400000; i <= 400000; i++){
        ans = max(ans, m[i]);
    }
    cout << ans << endl;
    return 0;
}