#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    if((n-1) / 2 + 1 < k){
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