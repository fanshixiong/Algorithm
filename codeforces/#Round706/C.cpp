#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;

ll a[maxn], b[maxn];

void solve(){
    int n; cin >> n;
    int ca = 0, cb = 0;
    for(int i = 1; i <= 2 * n; i++){
        int x, y; cin >> x >> y;
        if(x == 0) b[++ca] = abs(y);
        if(y == 0) a[++cb] = abs(x);
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    double ans = 0.0;
    for(int i = 1; i <= n; i++){
        ans += sqrt(a[i] * a[i] + b[i] * b[i]);
    }
    printf("%.15lf\n", ans);
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}