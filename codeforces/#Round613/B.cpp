#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+7;
ll p[maxn];
ll a[maxn], suffix[maxn], prefix[maxn];  
void solve(){
    int n;
    cin >> n;
    bool flg = 0;
    suffix[n + 1] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        prefix[i] = prefix[i-1] + a[i];
        if(prefix[i] <= 0){
            flg = 1;
        }
        //cout << prefix[i] << " ";
    }
    //cout << endl;
    for (int i = n; i > 0; i--){
        suffix[i] = suffix[i+1] + a[i];
        if(suffix[i] <= 0){
            flg = 1;
            break;
        }
        //cout << suffix[i] << " ";
    }
    cout << (flg ? "NO" : "YES") << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    ll n, m, ans=0;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}