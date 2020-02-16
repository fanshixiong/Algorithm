#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;

void solve(){
    string s;
    cin >> s;
    int ans = 0;
    int l = 0, r = s.size()-1;
    while(l<=r && s[l]=='0'){l++;}
    while(l<=r && s[l]=='1'){l++;}
    while(0<=r && s[r]=='0'){r--;}
    while(0<=r && s[r]=='1'){r--;}
    //cout << l << " " << r << endl;
    for (int i = l; i<=r; i++){
        if(s[i] == '0')
            ans++;
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