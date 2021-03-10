#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    if(k == 0){
        cout << "YES" << endl;
        return;
    }
    int l = 0, r = n - 1;
    while(l <= r && s[l] == s[r]){
        l++; r--;
    }
    // cout << l << endl;
    if(l > k || (l == k && r-l > 0)) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
/*
8
5 1
qwqwq
2 1
ab
3 1
ioi
4 2
icpc
22 0
dokidokiliteratureclub
19 8
imteamshanghaialice
6 3
aaaaaa
6 2
aabcaa

*/