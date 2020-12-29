#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e3 + 10;
const int INF = 0x3f3f3f3f;

string a[maxn];

void solve(){
    int ans[10] = {0};
    int maxr[10] = {0}, minr[10];
    int maxc[10] = {0}, minc[10];
    for(int i = 0; i < 10; ++i) minr[i] = minc[i] = INF;
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        for(int j = 0; j < n; ++j) {
            int x = a[i][j] - '0';
            maxr[x] = max(maxr[x], i), minr[x] = min(minr[x], i);
            maxc[x] = max(maxc[x], j), minc[x] = min(minc[x], j);
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int x = a[i][j] - '0';
            ans[x] = max(ans[x], max(i-minr[x], maxr[x]-i) * max(n-j-1, j));
            ans[x] = max(ans[x], max(j-minc[x], maxc[x]-j) * max(n-i-1, i));
        }
    }
    for(int i = 0; i < 10; ++i) cout << ans[i] << " ";
    cout << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}