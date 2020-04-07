#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int dp[505][505], a[505][505];
/*
void solve(){
    //int k; cin >> k;
    memset(dp, 0, sizeof(dp));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    cout << endl;
    dp[0][1] = a[1][1];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] = max(dp[i - 1][j] & a[i][j], dp[i][j - 1] & a[i][j]);
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[n][m] << endl; 
}
*/
int main(){
    IOS;
    /*
    int t; t = 1;
    while(t--){
        solve();
    }*/
    int k;
    cin >> k;
    int dp[2][3];
    dp[0][0] = dp[1][1] = (1 << 18) - 1;
    dp[0][1] = dp[1][0] = (1 << 17); dp[1][0]--;
    dp[0][2] = 0;
    dp[1][2] = k;
    cout << 2 << " " << 3 << endl;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
        return 0;
}