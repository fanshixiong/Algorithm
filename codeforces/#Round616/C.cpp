#include<bits/stdc++.h>
using namespace std;
const int maxn = 3510;
int a[maxn];
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    k = min(m - 1, k);
    int ans = 0;
    for (int i = 0; i <= k; i++){
        int tp = 0x3f3f3f3f;
        for (int j = k; j < m; j++){
            tp = min(tp, max(a[i + j - k], a[n - 1 - (k - i) - (m - 1 - j)]));
        }
        ans = max(ans, tp);
    }
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}