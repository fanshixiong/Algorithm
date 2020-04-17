#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int n, a, b; cin >> n >> a >> b;
    if(a == b) {
        int len = 0, c = 0;
        while(len++ < n){
            cout << (char)(c + 'a');
            c = (c + 1) % 26;
        }
        cout << endl;
        return;
    }
    if(b == 1){
        int len = 0;
        while(len++ < n){
            cout << 'a';
        }
        cout << endl;
        return;
    }
    int len = 0, ov = 1, c = 0;
    while(len++ < n){
        cout << (char)(c + 'a');
        if(c == 0 && ov < a -  b + 1){
            ov++;
            continue;
        }
        c = (c + 1) % b;
        ov = 1;
    }
    cout << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}