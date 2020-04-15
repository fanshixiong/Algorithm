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
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    string prefix = "", suffix = "";
    vector<string> mid;
    for (string& str : s){
        int star = -1;
        for (int i = 0; i < (int)str.size(); i++){
            if(str[i] == '*'){
                if (star == -1){
                    string sub = str.substr(0, i);
                    if(prefix.size() < sub.size()) swap(prefix, sub);
                    if(!startsWith(prefix, sub)) return "*";
                }
                else{
                    mid.push_back(str.substr(star + 1, i - star - 1));
                }
                star = i;
            }
        }
        string sub = str.substr(star + 1);
        if(suffix.size() < sub.size()) swap(suffix, sub);
        if(!endsWith(suffix, sub)) return "*";
    }
    string ans = prefix;
    for(string& s : mid) ans += s;
    ans += suffix;
    return ans;
}
int main(){
    IOS;
    int t, k = 0;
    cin >> t;
    while(k++ < t){
        cout << "Case #" << k << ": " << solve() << endl;
    }
    return 0;
}