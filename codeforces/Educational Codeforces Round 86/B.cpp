#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    string s; cin >> s;
    int x = s[0] - '0';
    for (int i = 0; i < s.size(); i++){
        if(s[i] - '0' != x){
            string ans;
            for (int i = 0; i < s.size(); i++) ans += "01"; 
            cout << ans << endl;
            return;
        }
    }
    cout << s << endl;         
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}