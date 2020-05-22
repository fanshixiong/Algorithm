#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.141592653589
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    double n; cin >> n;
    double ans = 1.0 / sin(PI / 2.0 / n) * cos(PI / 4.0 / n);
    printf("%.7lf\n", ans);
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}