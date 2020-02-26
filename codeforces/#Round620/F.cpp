#include<bits/stdc++.h>
using namespace std;
const int N = 55, M = 2e4 + 5;
int n, m, k;
int sum[N][M], dp[N][M], lmax[N][M], rmax[N][M];
int get(int p, int y, int d){
    return sum[p][d] - sum[p][y - 1];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> sum[i][j];
            sum[i][j] += sum[i][j - 1];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m - k + 1; j++){
            int ksum = get(i, j, j + k - 1) + get(i + 1, j, j + k - 1);
            if(i == 1){//first day
                dp[i][j] = ksum;
                continue;
            }
            for (int x = max(1, j - k + 1); x <= min(j + k - 1, m - k + 1); x++){
                dp[i][j] = max(dp[i][j], dp[i - 1][x] + ksum - get(i, max(x, j), min(j + k - 1, x + k - 1)));
            }

            if(j > k)
                dp[i][j] = max(dp[i][j], lmax[i - 1][j - k] + ksum);
            if(j + k <= m)
                dp[i][j] = max(dp[i][j], rmax[i - 1][j + k] + ksum);
            
        }

        for (int j = 1; j <= m - k + 1; j++){
            lmax[i][j] = max(dp[i][j], lmax[i][j - 1]);
        }
        for (int j = m - k + 1; j >= 1; j--){
            rmax[i][j] = max(dp[i][j], rmax[i][j + 1]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= m - k + 1; i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}