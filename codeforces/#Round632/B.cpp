#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn], b[maxn];
void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    bool pos = false, neg = false;
    for (int i = 0; i < n; i++){
        if(a[i] < b[i] && !pos){
            cout << "NO" << endl;
            return;
        }
        if(a[i] > b[i] && !neg){
            cout << "NO" << endl;
            return;
        }
        if(a[i] == 1) pos = true;
        if(a[i] == -1) neg = true;
        if(pos && neg) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
int main(){
    IOS;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}