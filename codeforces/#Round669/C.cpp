#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
ll a[maxn];
void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool ok = 0;
    for (int i = 0; i < k; i++){
        char c = s[i];
        bool flg = 0;
        for (int j = i; j < s.size(); j += k){
            if(s[j] == '?') continue;
            if (c == '?' && s[j] != '?'){
                c = s[i] = s[j];
                continue;
            }
            if(c != '?' && s[j] != c){
                flg = 1;
                break;
            }
        }
        if(flg){
            ok = 1;
            break;
        }
    }

    int a = 0, b = 0;
    for(int i=0; i<k; i++){
        if(s[i] == '0') a++;
        else if(s[i] == '1') b++;
    }
    if(a>k/2 || b>k/2) ok=1;
    if(ok) cout << "NO" << endl;
    else cout << "YES" << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}