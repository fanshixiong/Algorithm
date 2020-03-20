#include<bits/stdc++.h>
using namespace std;
int a[1100];
void solve(){
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    for (int i = m; i >= 0; i--){
        if(i <= sum){
            cout << i << endl;
            return;
        }
    }
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