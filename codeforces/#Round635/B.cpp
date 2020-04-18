#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int x, n, m; cin >> x >> n >> m;
    while(x > 0 && x / 2 + 10 < x && n){
        n--;
        x = x / 2 + 10;
    }
    while(x > 0 && m){
        m--;
        x -= 10;
    }
    /*
    while(x > 0){
        if(x / 2 + 10 <= x - 10){
            if(n > 0) x = x / 2 + 10, n--;
            else if(m > 0){ x = x - 10; m--;}
        }
        else{
            if(m > 0) x = x - 10, m--;
            else if(n > 0){x = x / 2 + 10; n--;}
        }
        if(n<=0 && m<=0){
            break;
        }
        cout << x << " " << n << " " << m << endl;
    }
    */
    if(x <= 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}