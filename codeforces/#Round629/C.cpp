#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    string s;
    cin >> n >> s;
    string t1, t2;
    bool flg = 0;
    for (int i = 0; i < n; i++){
        if(s[i] == '0'){
            t1 += '0'; t2 += '0';
        }
        else if(s[i] == '1'){
            if(!flg){
                t1 += '1'; t2 += '0'; flg = 1;
            }
            else{
                t1 += '0'; t2 += '1';
            }
        }
        else{
            if(flg){
                t2 += '2'; t1 += '0';
            }
            else{
                t1 += '1'; t2 += '1';
            }
        }
    }
    cout << t1 << endl << t2 << endl;
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