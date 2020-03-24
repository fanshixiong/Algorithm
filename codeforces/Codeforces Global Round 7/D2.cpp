#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll maxlen, flg;
string Manacher(string s1){
    string s = "$#";
    for (int i = 0; i < s1.size(); i++){
        s += s1[i], s += '#';
    }
    vector<ll> p(s.size(), 0);
    ll c = 0, ra = 0;
    maxlen = 0; flg = 0;
    for (int i = 1; i < s.size(); i++){
        p[i] = ra > i + p[i] ? min(p[2 * c - i], ra - i) : 1;
        while(s[i+p[i]] == s[i-p[i]]) ++p[i];
        if(ra < i+p[i]){
            c = i; ra = i+p[i];
        }
        if(i == p[i] && maxlen < p[i]){
            maxlen = p[i] - 1; flg = 1;
        }
        if(i+p[i] == s.size() && maxlen < p[i]){
            maxlen = p[i] - 1, flg = 2;
        }
    }
    if(flg == 1)
        return s1.substr(0, maxlen);
    else{
        return s1.substr(s1.size() - maxlen);
    }
}
void solve(){
    string src; cin >> src;
    ll l = 0, r = src.size() - 1;
    while(l<r && src[l] == src[r]){l++, r--;}
    if(l >= r){
        cout << src << endl;
        return;
    }
    //cout << src.substr(l, r - l + 1) << "  ";
    string mid = Manacher(src.substr(l, r-l+1));
    //cout << mid << endl;
    cout << src.substr(0, l) + mid + src.substr(r+1) << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    ll t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}