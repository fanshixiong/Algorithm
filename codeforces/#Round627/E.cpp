#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 10;
int l, r, n, h;
int t[maxn], dp[maxn][maxn];
// dp[i][j] 表示完成前i次睡眠并且共少间隔了j小时的最多goodsleep次数
// 状态转移：dp[i+1][j] = max(dp[i+1][j], dp[i][j] + 当前时间是否在范围内)

int goodSleep(int x){
    x = (x % h + h) % h;
    return l <= x && x <= r ? 1 : 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> h >> l >> r;
    t[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> t[i];
        t[i] += t[i - 1];
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j ++){
            if(dp[i][j] == -1)
                continue;
            int cur = t[i + 1] - j;
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + goodSleep(cur));
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + goodSleep(cur-1));
        }
    }
    int ans = -1;
    for (int i = 0; i <= n; i++){
        ans = max(dp[n][i], ans);
    }
    cout << ans << endl;
    return 0;
}