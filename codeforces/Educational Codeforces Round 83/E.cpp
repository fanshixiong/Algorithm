#include<bits/stdc++.h>
using namespace std;
const int maxn = 510;
int a[maxn], dp[maxn], sum[maxn][maxn];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i][i] = a[i];
    }
    for (int len = 1; len <= n; len++){
        for (int i = 1; i <= n - len; i++){
            int j = len + i;
            for (int k = i; k < j; k++){
                if(sum[i][k] == sum[k+1][j] && sum[i][k] != 0){
                    sum[i][j] = sum[i][k] + 1;
                }
            }
        }
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        dp[i] = dp[i - 1] + 1;
        for (int j = 1; j <= i; j++){
            if(sum[j][i] > 0){
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    cout << dp[n] << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}