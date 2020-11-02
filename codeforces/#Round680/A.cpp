#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn], b[maxn];
void solve(){
    int n, x; cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);

    for (int i = 0; i < n; i++){
        int p = n - i - 1;
        if(a[i] + b[p] > x){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}