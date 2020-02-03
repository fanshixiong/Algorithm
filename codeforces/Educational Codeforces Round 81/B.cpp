#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;
bool judge(int cur, int delta){
    if(delta < 0){
        delta = -delta;
        cur = -cur;
    }
    if(cur < 0)
        return false;
    return cur % delta == 0;
}
void solve(){
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    int delta = 0;
    for (int i = 0; i < n; i++){
        if(s[i] == '0')
            delta++;
        else
            delta--;
    }
    int cur = 0, ans = 0;
    
    for (int i = 0; i < n; i++){
        if(delta == 0 && cur == x){
            cout << -1 << endl;
            return;
        }
        if(delta != 0 && judge(x-cur, delta))
            ans++;
        if(s[i]=='0')
            cur++;
        else
            cur--;
    }
    cout << ans << endl;
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