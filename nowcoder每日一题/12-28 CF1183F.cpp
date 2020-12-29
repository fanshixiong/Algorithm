/*
https://ac.nowcoder.com/discuss/583121
贪心。三种情况
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];
int n;
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    vector<int> v;
    int f2 = 0, f5 = 0, f3 = 0;
    for(int i = 0; i < n; i++){
        if(a[n-1] % a[i] != 0) v.emplace_back(a[i]);
        if(a[n-1] / 2 == a[i] && a[n-1] % 2 == 0) f2 = 1;
        if(a[n-1] / 3 == a[i] && a[n-1] % 3 == 0) f3 = 1;
        if(a[n-1] / 5 == a[i] && a[n-1] % 5 == 0) f5 = 1;
    }

    int ans = a[n-1];
    sort(v.begin(), v.end());
    if(v.size()) ans += v.back();
    // cout << ans << endl;
    for(int i = v.size()-2; i >= 0; i--)
        if(v.back() % v[i] != 0){ans += v[i]; break;}
    if(f2 && f3 && f5) ans = max(ans, a[n-1] / 30 * 31);
    cout << ans << endl;;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}