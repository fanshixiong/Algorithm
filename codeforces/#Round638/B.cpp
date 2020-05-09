#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e2 + 10;
vector<int> v;
void print(){
    for (auto x : v) cout << x << " "; 
}
void solve(){
    int n, k; cin >> n >> k;
    map<int, int> vis;
    v.clear();
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if(!vis[x]){
            v.push_back(x);
            vis[x] = 1;
        }
    }
    if(v.size() > k){
        cout << -1 << endl;
        return;
    }
    int ct = k - v.size();
    if(ct > 0){
        for (int i = 0; i < ct; i++) v.push_back(1);
    }
    cout << n * k << endl;
    for (int i = 0; i < n; i++) print();
    cout << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
/*
5
4 1
3 1 1 2
4 3
1 4 2 1
3 3
2 1 3
4 4
2 2 4 1
2 2
1 2
*/