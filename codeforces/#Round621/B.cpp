#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+10;

void solve(){
    int n, x;
    cin >> n >> x;
    int maxn = 0, ans = 0;
    for (int i = 0; i < n; i++){
        int p;
        cin >> p;
        if(p == x)
            ans = 1;
        maxn = max(maxn, p);
    }
    if(ans){
        cout << ans << endl;
        return;
    }
    if(x % maxn==0){
        ans = x / maxn;
    }
    else
        ans = x / maxn + 1;
    cout << max(2, ans) <<endl;
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