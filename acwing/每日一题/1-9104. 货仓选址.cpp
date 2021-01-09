#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];
void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    int res = 0;
    int i = -1, j = n;
    while(++i < --j) res += a[j] - a[i];
    cout << res << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}