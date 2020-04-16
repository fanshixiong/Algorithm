#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 3e5 + 10;
int a[maxn];
void solve(){
    int n;  cin >> n;
    for (int i = 0; i<n; i++) cin >> a[i];
    sort(a, a + n);
    int r = n / 2, l = n / 2 - 1;
    while(l >= 0 && r < n){
        cout << a[r] << " " << a[l] << " ";
        l--; r++;
    }
    while(l >= 0) cout << a[l--] << " ";
    while(r < n) cout << a[r++] << " ";
    cout << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}