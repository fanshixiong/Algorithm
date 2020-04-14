#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;

bool startsWith(string s, string sub){
        return s.find(sub) == 0 ? 1 : 0;
}
bool endsWith(string s, string sub){
        return s.rfind(sub) == (s.length() - sub.length()) ? 1 : 0;
}

string solve(){
    int n; cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    string ans;
    vector<string> prefix, suffix;
    for (int i = 0; i < n; i++){
        int j = 0;
        while(s[i][j++] != '*'){}
        string tmp = s[i].substr(0, j);
        if(j > 1) prefix.push_back(tmp);
        j = s[i].size() - 1;
        while(s[i][j--] != '*'){}
        tmp = s[i].substr(j, s[i].size() - j);
        if(j < s[i].size() - 2) suffix.push_back(tmp);
    }
    sort(prefix.begin(), prefix.end());
    sort(suffix.begin(), suffix.end());
    string pre = prefix[prefix.end() - 1], suf = suffix[suffix.end() - 1];
    string mid = "";
    for (int i = 0; i < suffix.size() - 1; i++){
        if(!endwith(suf, suffix[i])){
            return "";
        }
    }
    return suf;
    for (int i = 0; i < prefix.size(); i++){
        if(!startsWith(pre, prefix[i])){
            return "";
        }
    }
}
int main(){
    IOS;
    int t, k = 0;
    cin >> t;
    while(k++ < t){
        cout << "Case #" << k << ": " << solve();
    }
    return 0;
}