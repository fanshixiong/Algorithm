#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e6 + 10;
ll d[maxn], day_sum[maxn], score_sum[maxn];
void solve(){
    ll n, x; cin >> n >> x;
    day_sum[0] = 0;
    score_sum[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> d[i];
        day_sum[i] = day_sum[i - 1] + d[i];
        score_sum[i] = score_sum[i - 1] + (1 + d[i]) * d[i] / 2;
    }
    for (int i = n + 1; i <= 2 * n; i++){
        d[i] = d[i - n];
        day_sum[i] = day_sum[i - 1] + d[i];
        score_sum[i] = score_sum[i - 1] + (1 + d[i]) * d[i] / 2;
    }
    n *= 2;
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        ll pos = lower_bound(day_sum, day_sum + 1 + n, day_sum[i] - x) - day_sum;
        if(pos == 0) continue;

        ll remain = day_sum[i] - x - day_sum[pos - 1];
        ans = max(ans, score_sum[i] - score_sum[pos - 1] -  (1 + remain) * remain / 2);
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