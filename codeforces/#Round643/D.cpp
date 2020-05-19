#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    ll n, s; cin >> n >> s;
    if(s / n >= 2){
        cout << "YES" << endl;
        for (int i = 0; i < n - 1; i++) cout << 2 << " ";
        cout << s - (n - 1) * 2 << endl;
        cout << 1 << endl;
    }else{
        cout << "NO" << endl;
    }
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}