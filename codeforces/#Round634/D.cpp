#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    vector<string> s(9);
    for(int i = 0; i < 9; i++) cin >> s[i];
    s[0][1] = s[0][0];
    s[1][5] = s[1][4];
    s[2][6] = s[2][8];
    s[3][2] = s[3][1];
    s[4][3] = s[4][5];
    s[5][7] = s[5][6];
    s[6][0] = s[6][2];
    s[7][4] = s[7][3];
    s[8][8] = s[8][7];
    for(int i = 0; i < 9; i++) cout << s[i] << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}