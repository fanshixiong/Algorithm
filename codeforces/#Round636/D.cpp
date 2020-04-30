/*
    如果定值在 [2,minn]  之间，此时这两个数都需要更改。这段区间的操作数 +2。
    如果定值在 [maxn+k+1,2∗k]  之间，此时这两个数都需要更改，这段区间的操作数 +2 。
    如果定值在 [minn+1,maxn+k]  之间且不等于 sumsumsum ,能够做到只改变其中一个数就使得和等于定值。这个范围内操作数+1.
    特殊处理，如果定值等于sum,不需要更改任何一个数,所以这个点的操作数不需要增加。
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 4e5 + 10;
ll a[maxn], b[maxn];
void solve(){
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(b, 0, sizeof b);
    for (int i = n / 2 + 1; i <= n; i++){
        int minn = min(a[i], a[n - i + 1]), maxx = max(a[i], a[n - i + 1]);
        ll sum = minn + maxx;
        b[2] += 2; b[minn + 1]--;
        b[maxx + k + 1]++; b[2 * k + 1] -= 2;
        b[sum]--; b[sum + 1]++;
    }
    ll ans = b[2];
    for (int i = 3; i <= 2 * k; i++){
        b[i] += b[i - 1];
        ans = min(ans, b[i]);
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