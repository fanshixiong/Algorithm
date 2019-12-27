#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll x;
    cin >> x;
    ll mod = x%14;
    ll t = x/14;
    if(t && (mod >=1 && mod <=6)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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