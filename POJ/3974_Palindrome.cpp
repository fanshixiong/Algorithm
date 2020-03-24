//#include <bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
string Manacher(string s1){
    string s = "$#";
    for (int i = 0; i < s1.size(); i++){
        s += s1[i], s += '#';
    }
    vector<int> p(s.size(), 0);
    int c = 0, r = 0, maxlen = 0, maxpoint = 0;
    for (int i = 1; i < s.size(); i++){
        p[i] = r > i + p[i] ? min(p[2 * c - i], r - i) : 1;
        while(s[i+p[i]] == s[i-p[i]]) ++p[i];
        if(r < i+p[i]){
            c = i; r = i+p[i];
        }
        if(maxlen < p[i]){
            maxlen = p[i]; maxpoint = i;
        }
    }
    return s1.substr((maxpoint - maxlen) / 2, maxlen - 1);
}
int main(){
    ios_base::sync_with_stdio(0);
    string s;
    int ans = 1;
    while(cin >> s){
        if(s == "END") break;
        s = Manacher(s);
        cout << "Case " << ans++ << ": " << s.size() << endl;
    }
    return 0;
}