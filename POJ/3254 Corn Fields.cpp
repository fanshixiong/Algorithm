/*状态压缩DP

*/

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e8;
int dp[13][1 << 12];
int maze[12][12];

int lowbit(int x){
    return x & -x;
}
int getcount(int x){
    int res = 0;
    while(x){
        res++;
        x -= lowbit(x);
    }
    return res;
}
int  main() {
    ios::sync_with_stdio(0);
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> maze[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 0;

    int lim = 1 << n;
    for (int i = 1; i <= m; i++){
        for (int pre = 0; pre<lim; pre++){
            for (int cur = 0; cur < lim; cur++){

                if(dp[i-1][pre] == -1)
                    continue;

                bool flg = 0;
                for (int j = 0; j < n; j++){
                    if(((cur>>j)&1) == 0)
                        continue;
                    if(maze[i-1][j] == 0)
                        flg = 1;
                    if(j>=1 && ((cur>>(j-1))&1))
                        flg = 1;
                    if(j<n-1 && ((cur>>(j+1))&1))
                        flg = 1;
                    if((pre>>j) & 1)
                        flg = 1;
                }
                if(flg)
                    continue;
                dp[i][cur] = (dp[i][cur]+(dp[i - 1][pre] + getcount(cur)))%mod;
                //cout << dp[i][cur] << endl;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i<lim; i++)
        ans = (ans + dp[m][i]) % mod;
    cout << ans << endl;
    return 0;
}