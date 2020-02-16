#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;

void solve(){
    string a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i < a.size(); i++){
        if( c[i] == a[i] || c[i] == b[i])
            continue;
        else{
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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