#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int findX(string s, string tar){
    int cnt = 0;
    for(int i = 0; i < s.size(); i ++){
        if(s.substr(i, 7) == tar) cnt++;
    }
    return cnt == 1;
}
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    string tar = "abacaba";

    for(int i = 0; i < s.size(); i++){
        string tmp = s;
        bool flg = 1;
        for (int j = 0; j < 7; j++){
            if(tmp[i+j] != tar[j] && tmp[i+j] != '?'){
                flg = 0;
                break;
            }
            tmp[i+j] = tar[j];
        }
        if(flg && findX(tmp, tar)){
            for (int j = 0; j < tmp.size(); j++){
                if(tmp[j] == '?') tmp[j] = 'z';
            }
            cout << "Yes" << endl;
            cout << tmp << endl;
            return;
        }
    }
    cout << "no" << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}