#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int n; cin >> n;
    string s[n];
    bool flg = 0;
    for (int i = 0; i < n; i++) cin >> s[i];

    for(int i = n-2; i >= 0; i--){
        for (int j = n - 2; j >= 0; j--){
            if(s[i][j] == '1' && (s[i+1][j] != '1' && s[i][j+1] != '1')){
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}