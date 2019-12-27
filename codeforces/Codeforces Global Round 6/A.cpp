#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin >> s;
    int three=0, zero=0, odds=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]-'0' == 0)
            zero++;
        if((s[i]-'0')%2==0)
            odds++;
        three +=(s[i]-'0');
    }
    if(three % 3==0 && zero && odds>1){
        cout << "red" << endl;
    }
    else{
        cout << "cyan" << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}