#include<bits/stdc++.h>
using namespace std;
int main(){
    string s; cin >> s;
    map<char, int> p;
    string ans;
    for(auto c : s) {
        if(p[c]) continue;
        p[c]++;
        ans += c;
    }
    cout << ans << endl;
    return 0;
}