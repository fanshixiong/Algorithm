#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin >> s;
    int ans = 0, cnt = 0;
    for (int i = 0; i < s.size(); i++){
        if(s[i] == 'L'){
            cnt++;
        }
        else{
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    cout << max(ans, cnt) + 1 << endl;
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