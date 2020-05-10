#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int n; cin >> n;
    vector<int> ans;
    int rd = 1, rem;
    while(n){
        rem = n % 10;
        if(rem){
            ans.push_back(rem * rd);
        }
        n /= 10;
        rd *= 10;
    }
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}