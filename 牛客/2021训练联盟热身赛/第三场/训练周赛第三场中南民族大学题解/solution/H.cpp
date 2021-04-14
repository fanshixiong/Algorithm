#include <bits/stdc++.h>
using namespace std;

int n;
int v[505][505];
int dp[505][505];

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) cin >> v[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n - i; ++j)
            for (int k = j; k <= j + i; ++k)
                dp[j][j + i] = max(dp[j][j + i], dp[j + 1][k - 1] + v[j][k] + dp[k + 1][j + i]);
    cout << dp[1][n];
    return 0;
}