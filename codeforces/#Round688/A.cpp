#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn], b[maxn];
void solve(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int lu = abs(1 - x) + abs(1 - y);
    int ld = abs(n - x) + abs(1 - y);
    int ru = abs(1 - x) + abs(m - y);
    int rd = abs(n - x) + abs(m - y);
    cout << max(max(lu, max(ld, ru)), rd) << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}