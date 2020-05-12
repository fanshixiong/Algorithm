#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 8e3 + 10;
int a[maxn], v[maxn];
void solve(){
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;
    vector<int> ans;
    if(n1 || n2) ans.push_back(1);
    for (int i = 0; i < n2; i++) ans.push_back(1);
    for (int i = 0; i < n1 / 2; i++){
        ans.push_back(0);
        ans.push_back(1);
    }
    if (n1 & 1){
        ans.push_back(0);
        for (int i = 0; i < n0; i++) ans.push_back(0);
    }
    else{
        if(ans.size()){
            ans.pop_back();
            for (int i = 0; i < n0; i++) ans.push_back(0);
            ans.push_back(1);
        }
        else{
            for (int i = 0; i < n0 + 1; i++) ans.push_back(0);
        }
    }
    for (auto x : ans) cout << x;
    cout << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}