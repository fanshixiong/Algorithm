#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;

void solve(){
    int a, b;
    cin >> a >> b;
    if(a == b){
        cout << 0 << endl;
        return;
    }

    //cout << (a & 1) << "  safdbkasgf" << (b & 1) << endl;
    if((a&1) && (b&1)){
        if(a < b){
            cout << 2 << endl;
        }
        else{
            cout << 1 << endl;
        }
    }
    else if((a&1) && !(b&1)){
        if(a < b){
            cout << 1 << endl;
        }
        else{
            cout << 2 << endl;
        }
    }
    else if(!(a&1) && (b&1)){
        if(a < b){
            cout << 1 << endl;
        }
        else{
            cout << 2 << endl;
        }
    }
    else{
        if(a < b){
            cout << 2 << endl;
        }
        else{
            cout << 1 << endl;
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