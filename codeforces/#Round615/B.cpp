#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end());
    string ans;
    pair<int, int> cur = make_pair(0, 0);
    for (int i = 0; i < n; i++){
        int r = v[i].first - cur.first;
        int u = v[i].second - cur.second;
        if(r < 0 || u < 0){
            cout << "NO" << endl;
            return;
        }
        ans += string(r, 'R');
        ans += string(u, 'U');
        cur = v[i];
    }
    cout << "YES" << endl << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}