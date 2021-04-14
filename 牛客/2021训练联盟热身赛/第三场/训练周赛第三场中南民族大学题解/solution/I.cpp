#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 550;
const ll inf = 0x3f3f3f3f3f;  //注意这里有5个3f，只有四个会过不了  
ll dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    ll n, m, t, d;
    ll sta[N];
    cin >> n >> m >> t >> d;
    memset(dp, inf, sizeof(dp));

    for (int i = 1; i <= t; i++) cin >> sta[i];
    sta[t + 1] = 1, sta[t + 2] = n;

    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = c;
        dp[b][a] = c;
    }
    //第一遍floyd是为了知道每一对点之间的最短距离，如果最短距离仍然大于d那么一定不能跑  
    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    //处理距离大于d的数据  
    for (ll i = 1; i <= t + 2; i++) {
        for (ll j = 1; j <= t + 2; j++) {
            ll di = sta[i], dj = sta[j];
            if (dp[di][dj] > d) dp[di][dj] = inf;
        }
    }
    //最短路算法  
    for (ll k = 1; k <= t + 2; k++) {
        for (ll i = 1; i <= t + 2; i++) {
            for (ll j = 1; j <= t + 2; j++) {
                ll di = sta[i], dj = sta[j], dk = sta[k];
                dp[di][dj] = min(dp[di][dj], dp[di][dk] + dp[dk][dj]);
            }
        }
    }
    //如果dp[1][n]==inf,那么说明路径没有被缩短过，输出stuck  
    if (dp[1][n] == inf) cout << "stuck";
    else cout << dp[1][n];
    return 0;
}