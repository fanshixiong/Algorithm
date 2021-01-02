#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define pi pair<int, int>
#define pb push_back
const int maxn = 2e3 + 10;
ll a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];
ll w[maxn][maxn];
ll n, k;
void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> w[i][j];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] = a[i-1][j-1] + w[i][j];
            if(i > k && j > k) a[i][j] -= w[i-k][j-k];
            b[i][j] = b[i-1][j-1] + w[i][j];
            if(i > k-1 && j > k-1) b[i][j] -= w[i-k+1][j-k+1];
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            c[i][j] = c[i-1][j+1] + a[i][j] + b[i-1][j] - a[i-k][j+k] - b[i-k][j+k-1];
            cout << i << "  " << j << endl;
            if(j <= n-k+1 && j >= k && i >= 2*k-1) ans = max(ans, c[i][j]);
        }
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