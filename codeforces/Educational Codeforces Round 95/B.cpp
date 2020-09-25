#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int n;
    cin >> n;
    vector<int> a, b, c;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a.emplace_back(x);
    }
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        b.emplace_back(x);
    }
    for (int i = 0; i < n; i++) if(!b[i])c.emplace_back(a[i]);

    sort(c.rbegin(), c.rend());

    for (int i = 0, j = 0; i < n; i++){
        if(b[i]) cout << a[i] << " ";
        else cout << c[j++] << " ";
    }
    cout << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}