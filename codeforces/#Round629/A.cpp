#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll a, b;
    cin >> a >> b;
    if(a <= b ){
        cout << b - a << endl;
        return;
    }
    if(a % b == 0){
        cout << 0 << endl;
        return;
    }
    cout << (a / b + 1) * b - a << endl;
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