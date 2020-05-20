#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn], b[maxn], c[maxn];
void solve(){
    string s;
    cin >> s;
    a[0] = b[0] = c[0] = 0;
    for (int i = 1; i <= s.length(); i++){
        if(s[i-1] == '1') a[i] = i; else a[i] = a[i-1];
        if(s[i-1] == '2') b[i] = i; else b[i] = b[i-1];
        if(s[i-1] == '3') c[i] = i; else c[i] = c[i-1];
    }
    
    int ans = s.length();
    if(!a[s.length()] || !b[s.length()] || !c[s.length()]) ans = 0;
    for (int i = 2; i <= s.length(); i++){
        if(!a[i] || !b[i] || !c[i]) continue;
        ans = min(ans, max(a[i], max(b[i], c[i])) - min(a[i], min(b[i], c[i])) + 1);
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