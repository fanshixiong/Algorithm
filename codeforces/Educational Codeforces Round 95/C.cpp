#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    double h, c, t; cin >> h >> c >> t;

    int l = 0, r = 0x3f3f3f3f;
    while(l < r){
        int mid = (l + r) >> 1;
        double avg = 1.0 * ((mid + 1) * h + mid * c) / (2 * mid + 1);
        if(avg > t) l = mid + 1;
        else r = mid;
    }
    int ans = 2;
    double exp = fabs(1.0 * (h + c) / 2 - t);
    for (int i = max(0, l - 10); i <= l+10; i ++){
        double avg = 1.0 * ((i + 1) * h + i * c) / (2 * i + 1);
        //cout << fabs(avg-1.0*t) << " " << i << " " << exp << endl;
        if(fabs(avg-1.0*t) < exp){
            ans = 2 * i + 1;
            exp = fabs(avg - 1.0*t);
        }
    }
    cout << ans << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}