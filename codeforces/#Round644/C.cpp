#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];
void solve(){
    int n; cin >> n;
    int e = 0, o = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] % 2 == 0){
            e++;
        }
        else o++;
    }
    if(e % 2 != o % 2){
        cout << "NO" << endl;
        return;
    }
    if(e % 2 == 0){
        cout << "YES" << endl;
        return;
    }
    sort(a, a + n);
    for (int i = 1; i < n; i++){
        if(a[i] % 2 != a[i-1] % 2  && a[i]-a[i-1] == 1){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}