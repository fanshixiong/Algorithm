#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];
void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = 1e15;
    sort(a, a + n);
    for (int i = 1; i < 1e6+5; i++){
        ll fac = 1, tmp = a[0] - 1;
        bool flag = false;
        for (int j = 1; j < n; j++){
            fac *= i;
            tmp += fabs(fac - a[j]);
            if(tmp >= ans){
                flag = true;
                break;
            }
        }
        if(flag) break;
        ans = min(ans, tmp);
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