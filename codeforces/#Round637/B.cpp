#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
ll a[maxn], p[maxn], pos[maxn];
void solve(){
    int n, k; cin >> n >> k;
    for (int i = 0; i <= n; i++) p[i] = pos[i] = 0;
    for (int i = 0; i < n; i++)  cin >> a[i];
    int l = n - 2;
    for (int i = 1; i < n - 1; i++){
        if(a[i] > a[i-1] && a[i] > a[i+1]) pos[i] = 1;
    }
    //for (int i = 0; i < n; i++) cout << pos[i] << " ";
    //cout << endl;
    ll peak = 0, ans = -1, left = -1;
    for (; l >= 0; l--){
        if(pos[l + 1]) peak++;
        if(l + k - 1 < n && pos[l + k - 1]) peak--;

        if(ans <= peak){
            ans = peak;
            left = l;
        }
    }
    cout << ans + 1 << " " << left + 1 << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}