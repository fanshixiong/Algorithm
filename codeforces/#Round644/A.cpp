#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int a, b; cin >> a >> b;
    if(a < b) swap(a, b);
    b *= 2;
    if(a < b) cout << b * b << endl;
    else  cout << a * a << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}