#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s1, s2;
int count(string s){
    int cnt=0;
    for(int i=0; i<s.size(); i++){
        for(int j=i-1; j>=0; j--){
            if(s[j] > s[i])
                cnt++;
        }
    }
    return cnt;
}
void solve(){
    int n;
    cin >> n;
    cin >> s1 >>  s2;
    string s3=s1, s4=s2;
    sort(s3.begin(), s3.end());
    sort(s4.begin(), s4.end());
    bool flg=0;
    for(int i=0; i<s3.size(); i++){
        if(s3[i] != s4[i]){
            cout << "NO" <<endl;
            return;
        }
    }
    for(int i=1; i<s3.size(); i++){
        if(s3[i]==s3[i-1]){
            cout << "YES" << endl;
            return;
        }
        if(s4[i]==s4[i-1]){
            cout << "YES" << endl;
            return;
        }
    }
    if(count(s1)% 2 == count(s2)%2){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    int q;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}