#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int n, len;
    cin >> n >> len;
    string s[n];
    for (int i = 0; i < n; i++) cin >> s[i];

    string ans = s[0];
    for (int i = 0; i < len; i++){
        int tmp = ans[i];
        for (char c = 'a'; c <= 'z'; c++){
            ans[i] = c;
            bool flg = true;
            for (int z = 0; z < n; z++){
                int cnt = 0;
                for(int x = 0; x < len; x++){
                    if(s[z][x] != ans[x]) cnt++;
                }
                if(cnt > 1){
                    flg = false;
                    break;
                }
            }
            if(flg){
                cout << ans << endl;
                return;
            }
        }
        ans[i] = tmp;
    }
    cout << -1 << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}