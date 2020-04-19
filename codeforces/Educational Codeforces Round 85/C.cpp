#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 3e5 + 10;
ll a[maxn], b[maxn], c[maxn];
//c数组代表杀掉第i个monster需要补的枪
void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    ll sum = 0; //总共需要补的枪
    for(int i = 0; i < n; i++){
        if(i == 0) c[i] = max((ll)0, a[0] - b[n - 1]);
        else c[i] = max((ll)0, a[i] - b[i - 1]);
        sum += c[i];
    }
    ll ans = 1e18;
    for(int i = 0; i < n; i++){
        ans = min(ans, sum - c[i] + a[i]); // 减去需要补的枪，加上第一枪需要的子弹
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