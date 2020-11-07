#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 3e5 + 10;
int a[maxn];
void solve(){
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<pi> num;
    for (int i = 1; i <= n; i++){
        if(i > 1 && a[i] > a[i-1]) num.push_back({a[i], i});
        if(i < n && a[i] > a[i+1]) num.push_back({a[i], i});
    }

    int pos = -1;
    for (auto p : num){
        if(pos == -1) pos = p.second;
        else if(a[pos] < p.first) pos = p.second;
    }
    cout << (pos == -1 ? -1 : pos) << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}