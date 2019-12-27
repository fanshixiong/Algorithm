#include<bits/stdc++.h>
using namespace std;
bool judge(string str, string s){
    int cha[30]={0};
    int n=str.length();
    for(int i=0; i<n; i++){
        cha[s[i]-'a']++;
        cha[str[i]-'a']--;
    }
    for(int i=0; i<27; i++){
        if(cha[i]){
            return false;
        }
    }
    return true;
}
void solve(){
    string s, tar;
    cin >> s >> tar;
    int n=s.length(), m=tar.length();
    if(n > m){
        cout << "NO" << endl;
        return;
    }
    for(int i=0; i<m; i++){
        for(int j=m-1; j>=0; j--){
            if(i>j)
                continue;
            string str = tar.substr(i, j-i+1);
            if(str.length() == n && judge(str, s)){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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