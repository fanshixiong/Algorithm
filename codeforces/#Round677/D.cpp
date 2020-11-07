#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 5e3 + 10;
int a[maxn];
void solve(){
    int n; cin >> n;
    unordered_map<int, vector<int>> p;
    for (int i = 0; i < n; i++){ 
        cin >> a[i];
        p[a[i]].push_back(i + 1);
    }

    if((int)p[a[0]].size() == n){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int pos = a[0];
    for(auto x : p){
        if(x.first == pos) continue;
        for(auto c : x.second) cout << 1 << " " << c << endl;
    }
    for(auto x : p){
        if(x.first != a[0]){
            pos = x.first;
            break;
        }
    }

    vector<int> t = p[a[0]];
    int q = p[pos][0];
    // cout << "at: " << pos << " " << t.size() << " " << q << endl;
    for (int i = 1; i < (int)t.size(); i++){
        cout << q << " " << t[i] << endl;
    }
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}