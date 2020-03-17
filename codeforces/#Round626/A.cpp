#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int a[maxn];
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        if(a[i]%2 == 0){
            cout << 1 << endl;
            cout << (i + 1) << endl;
            return;
        }
    }
    if (n == 1) {
        cout << -1 << endl;
    }
    else{
        cout << 2 << endl;
        cout << 1 << " " << 2 << endl;
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