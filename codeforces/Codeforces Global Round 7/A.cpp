#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    if(n == 1){
        cout << -1 << endl;
        return;
    }
    int sum = 0;
    for (int i = 1; i <= n - 2; i++){
        cout << 2;
        sum += 2;
    }
    if((sum + 2 + 3) % 3 == 0){
        cout << 4;
    }
    else{
        cout << 2;
    }
    cout << 3 << endl;
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