#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn], b[maxn], c[maxn];
void solve(){
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);

    for (int i = 0; i < k; i++){
        if(a[i] < b[n-i-1]) swap(a[i], b[n-i-1]);
        else break;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    cout << sum << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}