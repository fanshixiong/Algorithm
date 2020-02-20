#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;
vector<pair<int, string>> v, ans;
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n - 1; i++){
        if(m-1!=0){
            v.push_back({m - 1, "R"});
            v.push_back({m - 1, "L"});
        }
        v.push_back({1, "D"});
    }
    if(m-1!=0)
        v.push_back({m - 1, "R"});
    for (int i = 0; i < m - 1; i++){
        if(n-1!=0){
            v.push_back({n - 1, "U"});
            v.push_back({n - 1, "D"});
        }
        v.push_back({1, "L"});
    }
    if(n-1!=0)
        v.push_back({n - 1, "U"});
    for (int i = 0; i < v.size(); i++){
        if(k>=v[i].first){
            k -= v[i].first;
            ans.push_back(v[i]);
        }
        else if(k!=0 && v[i].first>k){
            ans.push_back({k, v[i].second});
            k = 0;
        }
    }
    if(k>0){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        cout << ans.size() <<endl;
        for (int i = 0; i < ans.size();  i++){
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}