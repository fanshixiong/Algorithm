#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2010;
int val[20] = {119, 18, 93, 91, 58, 107, 111, 82, 127, 123}, a[maxn], ans[maxn];
int n, k, x;
int dp[maxn][maxn];
void dfs(int step, int kk){
    if(kk < 0) return;
    if(dp[step][kk]) return;
    dp[step][kk] = true;
    if(step == n){
        if(kk == 0){
            for (int i = 0; i < n; i++)cout << ans[i];
            exit(0);
        }
        return;
    }
    for (int i = 9; i >= 0; i--){
        if((val[i] & a[step]) == a[step]){
            ans[step] = i;
            dfs(step + 1, kk - __builtin_popcount(val[i] ^ a[step]));
        }
    }
}
void solve(){
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 7; j++){
            scanf("%1d", &x);
            a[i] = (a[i] << 1) + x;
        }
    }
    memset(dp, 0, sizeof dp);
    dfs(0, k);
    cout << -1 << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}