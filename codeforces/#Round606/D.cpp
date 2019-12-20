#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
string s[maxn];
void solve(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> s[i];
    set<string> seen, bad;
    int zz=0, zo=0, oz=0, oo=0;
    for(int i=0; i<n; i++){
        string t = s[i];
        if(t[0] == '0' && t[t.length()-1] == '0')
            zz++;
        else if(t[0] == '0'){
            zo++;
            string rev(t.rbegin(), t.rend());
            if(seen.count(rev)){
                bad.insert(rev);
                bad.insert(t);
            }
            seen.insert(t);
        }
        else if(t[t.length()-1] == '0'){
            oz++;
            string rev(t.rbegin(), t.rend());
            if(seen.count(rev)){
                bad.insert(rev);
                bad.insert(t);
            }
            seen.insert(t);
        }
        else
            oo++;
        
    }
    if(zo == 0 && oz == 0){
        if(zz == 0 || oo == 0)
            cout << 0 << endl << endl;
        else 
            cout << -1 << endl;
    }
    else{
        int ans = abs(oz-zo)/2;
        cout << ans << endl;
        for(int i=0; i<n; i++){
            if(ans == 0)
                break;
            if(zo > oz && s[i][0]=='0' && s[i].back() == '1' && !bad.count(s[i])){
                ans--;
                cout << i+1 << " ";
            }
            if(oz > zo && s[i][0]=='1' && s[i].back() == '0' && !bad.count(s[i])){
                ans--;
                cout << i+1 << " ";
            }
        }
        cout << endl;
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