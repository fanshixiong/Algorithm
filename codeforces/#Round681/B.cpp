#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];
void solve(){
    int a, b;
    cin >> a >> b;
    string s; cin >> s;

    vector<int> p;
    for (int r = 0; r < (int)s.size(); r++){
        if(s[r] == '1') p.push_back(r);
    }
    if((int)p.size() == 0){
        cout << 0 << endl;
        return;
    }
    
    ll sum = a;
    for (int i = 1; i < (int)p.size(); i++){
        if(p[i]-p[i-1] <= 1) continue;
        sum += min((p[i]-p[i-1]-1)*b, a);
    }
    cout << sum << endl;
}  
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}