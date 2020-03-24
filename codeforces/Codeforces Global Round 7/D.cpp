#include<bits/stdc++.h>
using namespace std;
string s;
bool judge(int l, int r){
    while(l <= r && s[l] == s[r]){l++, r--;}
    return l > r;
} 
void solve(){
    cin >> s;
    int l = 0, r = s.size() - 1;
    while(l<r && s[l] == s[r]){l++, r--;}
    int ll, rr;
    for (ll = l; ll <= r; ll++){
        if(judge(ll, r))
            break;
    }
    for (rr = r; rr >= l; rr--){
        if(judge(l, rr))
            break;
    }
    string mid = rr - l > r - ll ? s.substr(l, rr - l + 1) : s.substr(ll, r - ll + 1);
    cout << s.substr(0, l) + mid + s.substr(r+1) << endl;
}
int main(){
    ios_base::sync_with_stdio();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}