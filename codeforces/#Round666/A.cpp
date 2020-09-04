#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int n; cin >> n;
    vector<string> s(n); 
    for(int i=0; i<n; i++) cin >> s[i];
    map<int, int> p;
    for(string st:s){
        for(auto c : st) p[c]++;
    }
    for(auto x : p){
        if(x.second % n){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}