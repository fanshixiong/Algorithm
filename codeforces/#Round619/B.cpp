#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5+10;
int a[maxn], n;

void solve(){
    int l = 1e9, r = 0;
    cin >> n;
    a[0] = -1; a[n+1]=-1;
    for (int i = 1; i<=n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        if(a[i] == -1){
            if(a[i-1] != -1){
                l = min(l, a[i-1]);
                r = max(r, a[i-1]);
            }
            if(a[i+1] != -1){
                l = min(l, a[i+1]);
                r = max(r, a[i+1]);
            }
        }
    }
    int minus = (l + r) / 2, ans = 0;
    for (int i = 1; i <= n; i++){
        if(a[i]==-1)
            a[i] = minus;
        if(i!=1)
            ans = max(ans, abs(a[i] - a[i - 1]));
    }

    cout << ans << " " << minus << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    //freopen("Bin.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}