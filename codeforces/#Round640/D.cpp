#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int n; cin >> n;
    vector<int> v;
    for (int i = 0; i < 30; i++){
        if((1 << i) > n) break;
        n -= (1 << i);
        v.push_back(1 << i);
    }
    if(n) v.push_back(n);
    sort(v.begin(), v.end());
    cout << v.size() - 1 << endl;
    for (int i = 1; i < v.size(); i++){
        cout << v[i] - v[i - 1] << " ";
    }
    cout << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}