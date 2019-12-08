#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin >> n;
    vector<int> res;
    res.push_back(n);
    ll x=1;
    while(x<=n){
        ll l=x, r=n+1, ans=1;
        ll d=n/l;
        while(l<=r){
            ll mid = (l+r)/2;
            if(n/mid == d){
                ans = l;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        x = ans+1;
        res.push_back(n/x);
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    cout << res.size() << endl;
    for(int i=0; i<res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}