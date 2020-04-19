#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2020;
const int mod = 1e9 + 7;
int a[maxn];
bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}
void solve(){
    int n; cin >> n;
    vector<pair<int, int>> v;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        v.push_back(make_pair(a[i], i));
    }
    sort(v.begin(), v.end(), cmp);
    int left = 1, right = n;
    ll ans = 0;
    for(auto x : v){
        int u = x.first, p = x.second;
        int pos = 0;
        
        if(abs(p - left) <= abs(p - right)){
            pos = abs(p - right);
            right--;
        }
        else{
            pos = abs(p - left);
            left++;
        }
        ans += (1ll) * (pos * u);
        cout << u << " " << p << " " << left << " " << right << " " << pos << " " << ans << endl;
    }
    cout << ans << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}