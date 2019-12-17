#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin >> s;
    if(s[s.size()-1] == 'o' && s[s.size()-2] == 'p'){
        cout <<  "FILIPINO" << endl;
        return;
    }
    if((s[s.size()-1] == 'u' && s[s.size()-2] == 's' && s[s.size()-3] == 'e'&& s[s.size()-4] == 'd') ||(s[s.size()-1] == 'u' && s[s.size()-2] == 's' && s[s.size()-3] == 'a'&& s[s.size()-4] == 'm')){
        cout << "JAPANESE" << endl;
        return;
    }
    if(s[s.size()-1] == 'a' && s[s.size()-2] == 'd' && s[s.size()-3] == 'i'&& s[s.size()-4] == 'n' && s[s.size()-5] == 'm'){
        cout << "KOREAN" << endl;
        return;
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