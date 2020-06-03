#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];
void solve(){
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + 1 + n);
    int i = n;
    for (; i >= 1; i--){
        if(a[i] < i + 1) break;
    }
    cout << i + 1 << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}