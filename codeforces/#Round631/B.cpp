#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    set<int> l, r;
    map<int, int> cnt;
    for (int i = 1; i <= n; i++) ++cnt[a[i]], r.insert(a[i]);
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++){
        l.insert(a[i]);
        if(--cnt[a[i]] == 0) r.erase(a[i]);
        if(*l.begin() == 1 && *l.rbegin() == i && l.size() == i && *r.begin() == 1 && *r.rbegin() == n-i && r.size() == n-i)
            ans.push_back(make_pair(i, n - i));
    }
    cout << ans.size() << endl;
    for(auto it : ans){
        cout << it.first << " " << it.second << endl;
    }
}
int main(){
    IOS;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}