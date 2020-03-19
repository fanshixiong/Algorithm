#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll u, v;
    cin >> u >> v;
    if(u > v || ((v - u) & 1)){
        cout << -1 << endl;
        return;
    }
    if(u == v){
        if(!u)
            cout << 0 << endl;
        else{
            cout << 1 << endl;
            cout << u << endl;
        }
        return;
    }
    ll x = (v - u) / 2, y = (v + u) / 2;
    if((x^y) == u && (x+y) == v){
        cout << 2 << endl;
        cout << x << " " << y << endl;
    }
    else{
        cout << 3 << endl;
        cout << u << " " << x << " " << x << endl;
    }
}
int main(){
    ios_base::sync_with_stdio();
    solve();
    return 0;
}