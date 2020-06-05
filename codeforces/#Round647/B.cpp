#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];
void solve(){
    string s;cin >> s;
    int suf0 = 0, suf1 = 0;
    for (auto c : s){
        if(c == '0') suf0++;
        else suf1++;
    }
    int ans = min(suf0, suf1);
    int pre0 = 0, pre1 = 0;
    for(auto c : s){
        if (c == '0'){
            pre0++; suf0--;
        }
        else{
            pre1++; suf1--;
        }
        ans = min(ans, pre0 + suf1);
        ans = min(ans, pre1 + suf0);
    }
    cout << ans << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}