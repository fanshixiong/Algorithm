#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;

void solve(){
    int x, n, y;
    cin >> n >> x >> y;
    int last = min(n, x - 1 + y - 1 + 1);
    int fir;
    if(x + y <= n){
        fir = 1;
    }
    else
        fir = min(n, x + y - n + 1);
    cout << fir << " " << last << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >>t;
    while(t--){
        solve();
    }
    return 0;
}