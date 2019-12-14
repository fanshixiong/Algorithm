#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    if(n == 1){
        if(s[0]=='?')
            s[0] = 'a';
        cout << s <<endl;
        return;
    }
    
    if(s[n-1] == s[n-2] && s[n-1] != '?'){
        cout << -1 << endl;
        return;
    }
    if(s[0] == '?'){
        if(s[1] == 'a')
            s[0] = 'b';
        else if(s[1] == 'b')
            s[0] = 'c';
        else
            s[0] = 'a';
        
    }
    if(s[n-1] == '?'){
        if(s[n-2] == 'a')
            s[n-1] = 'b';
        else if(s[n-2] == 'b')
            s[n-1] = 'c';
        else
            s[n-1] = 'a';
    }
    for(int i=1; i<n-1; i++){
        if(s[i] == s[i-1]){
            if(s[i] != '?'){
                cout << -1 << endl;
                return;
            }
        }
        if(s[i] == '?'){
            if(s[i-1] != s[i+1]){
                if(s[i+1] == '?'){
                    if(s[i-1] == 'a')
                        s[i] = 'b';
                    else if(s[i-1] == 'b')
                        s[i] = 'c';
                    else{
                        s[i] = 'a';
                    }
                    continue;
                }
                if((s[i-1] == 'a' && s[i+1] == 'b') || (s[i-1] == 'b' && s[i+1] == 'a'))
                    s[i] = 'c';
                else if((s[i-1] == 'a' && s[i+1] == 'c') || (s[i-1] == 'c' && s[i+1] == 'a'))
                    s[i] = 'b';
                else
                {
                    s[i] = 'a';
                }
                
            }
            else{
                if(s[i-1] == 'a')
                    s[i] = 'b';
                else if(s[i-1] == 'b')
                    s[i] = 'c';
                else
                {
                    s[i] = 'a';
                }
                
            }
        }
    }
    cout << s << endl;
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