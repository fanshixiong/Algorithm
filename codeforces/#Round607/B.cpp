#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s, c;
    cin >> s >> c;
    if(s < c){
        cout << s << endl;
        return;
    }
    vector<char> str;
    for(int i=0; i<s.size(); i++){
        str.push_back(s[i]);
    }
    sort(str.begin(), str.end());
    char t;
    int pos=0;
    string cmpa;
    for(int i=0; i<s.size(); i++){
        cmpa += str[i];
    }
    if(cmpa >= c){
        cout << "---" << endl;
        return;
    }
    for(int i=0; i<s.size(); i++){
        if(str[i] != s[i]){
            pos = i;
            t = str[i];
            break;
        }
    }
    int last = s.size()-1;
    for(int i=s.size()-1; i>=0; i--){
        if(s[i] == t){
            last = i;
            break;
        }
    }
    swap(s[pos], s[last]);
    if(s < c)
       cout << s << endl;
    else
    {
        cout << "---" << endl;
    }
    
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