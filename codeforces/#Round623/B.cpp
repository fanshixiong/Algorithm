#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a, b, p;
    cin >> a >> b >> p;
    string s;
    cin >> s;
    int i;
    for (i = s.size() - 2; i >= 0; i--){
        if(s[i] == 'A'){
            if(p < a)
                break;
            p -= a;
        }
        if(s[i] == 'B'){
            if (p < b) 
                break;
            p -= b;
        }
        while(i>0 && s[i] == s[i-1])
            i--;
    }
    cout << i + 2 << endl;
    
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