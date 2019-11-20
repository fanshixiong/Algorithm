#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    int cnt_s[3];
    int cnt=0;
    for(int i=0; i<n; i++){
        if(s[i] != t[i]){
            cnt++;
            if(cnt >  2){
                cout << "No" << endl;
                return ;
            }
            cnt_s[cnt]=i;
        }
    }
    if(cnt==1){
        cout << "No" << endl;
        return;
    }
    if(cnt==0){
        cout << "Yes" << endl;
        return;
    }
    swap(s[cnt_s[1]], t[cnt_s[2]]);
    if(s == t){
        cout << "Yes" << endl;
        return;
    }
    swap(s[cnt_s[1]], t[cnt_s[2]]);
    swap(s[cnt_s[2]], t[cnt_s[1]]);
    if(s == t){
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
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