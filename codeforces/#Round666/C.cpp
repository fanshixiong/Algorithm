#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
ll a[maxn];
void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    if(n == 1){
        cout << "1 1" << endl;
        cout << "0" << endl;
        cout << "1 1" << endl;
        cout << "0" << endl;
        cout << "1 1" << endl;
        cout << -a[0] << endl;
        return;
    }
    cout << "1 1" << endl;
    cout << -a[0] << endl;
    cout << 1 << " " << n << endl;
    cout << 0 << " ";
    for (int i = 1; i < n; i++){
        cout << 1ll * -n * a[i] << " ";
    }
    cout << endl;
    cout << 2 << " " << n << endl;
    for (int i = 1; i < n; i++){
        cout << 1ll * (n - 1) * a[i] << " ";
    }
    cout << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}