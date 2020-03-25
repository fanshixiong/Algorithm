#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n, k;
    cin >> n >> k;
    if((n-1) / 2 + 1 < k ||  k * k > n){
        cout << "NO" << endl;
        return;
    }
    if(k % 2 == n % 2){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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