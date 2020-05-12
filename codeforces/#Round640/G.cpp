#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 8e3 + 10;
int a[maxn], v[maxn];
void solve(){
    int n; cin >> n;
    if(n < 4){
        cout << -1 << endl;
        return;
    }
    for (int i = n - ((n & 1) == 0); i >= 5; i -= 2) cout << i << " ";
    cout << "3 1 4 2 ";
    for (int i = 6; i <= n - ((n & 1) == 1); i += 2) cout << i <<" ";
    cout << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}