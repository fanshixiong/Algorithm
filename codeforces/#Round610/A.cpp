#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a, b, c, r;
    cin >> a >> b >> c >> r;
    int L = c-r, R=c+r;
    int st = max(L, min(a, b));
    int ed = min(R, max(a, b));
    cout << abs(a-b) - max(0, ed-st) << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}