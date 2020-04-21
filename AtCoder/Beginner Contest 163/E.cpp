#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2020;
const int mod = 1e9 + 7;
ll a[maxn];
ll dp[maxn][maxn];
/*dp[l][r]：表示剩下的值会被放到[l, r]中，已经放好的点的最大快乐值是多少 
*/
bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b){
    return a.first > b.first;
}
void solve(){
    int n; cin >> n;
    vector<pair<ll, ll>> v;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        v.push_back(make_pair(a[i], i));
    }
    sort(v.begin(), v.end(), cmp);
    //memset(dp, 0, sizeof dp);
    /*
        枚举最大的放在最左边还是最右边，
        放在离他最远的地方不是最大的答案
        所以要用区间dp
    */
    dp[1][n] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            int l = j + 1, r = n - i + j;
            if(l - 1 >= 1) dp[l][r] = max(dp[l][r], dp[l - 1][r] + v[i - 1].first * abs(v[i - 1].second - l + 1));
            if(r + 1 <= n) dp[l][r] = max(dp[l][r], dp[l][r + 1] + v[i - 1].first * abs(v[i - 1].second - r - 1));
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i][i] + v[n - 1].first * abs(i - v[n - 1].second));
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