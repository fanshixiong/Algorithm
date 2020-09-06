#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
ll a[maxn];
void solve(){
    int n, x, y; 
    cin >> n >> x >> y;
    int diff = y - x;
    for (int delta = 1; delta <= diff; delta++){
        if(diff % delta)continue;
        if(diff / delta + 1 > n) continue;

        int k = min((y - 1) / delta, n - 1);
        int start = y - k * delta;
        for (int i = 0; i < n; i++){
            cout << start + delta * i << " ";
        }
        cout << endl;
        return;
    }
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}