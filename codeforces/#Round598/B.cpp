#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    string s;
    cin >> s;
    int cnt=0;
    string t;
    for(int i=0; i<n; i++){
        if(s[i]=='R'){
            if(b>0){
                b--;
                t+='P';
                cnt++;
            }
            else if(a>0){
                a--;
                t+='R';
            }
            else if(c>0){
                c--;
                t+='S';
            }
        }
        else if(s[i]=='P'){
            if(c>0){
                c--;
                t+='S';
                cnt++;
            }
            else if(b>0){
                b--;
                t+='P';
            }
            else if(a>0){
                a--;
                t+='R';
            }
        }
        else{
            if(a>0){
                a--;
                cnt++;
                t+='R';
            }
            else if(c>0){
                c--;
                t+='S';
            }
            else if(b>0){
                b--;
                t+='P';
            }
        }
    }
    int x;
    if(n%2)
        x=n/2+1;
    else
        x=n/2;
    
    if(cnt < x){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        cout << t << endl;
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