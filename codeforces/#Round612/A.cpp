#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int pos = -1;
    int ans = 0;
    for (int i = 0; i<n; i++){
        if(s[i] == 'A')
            pos = i;
        if(i-pos <= i)
            ans = max(ans, i - pos);
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