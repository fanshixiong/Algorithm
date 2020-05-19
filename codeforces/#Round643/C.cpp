/*
https://www.cnblogs.com/stelayuri/p/12903245.html
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    ll down = max(C + 1, B + A);


    ll ans = 0;
    for (ll i = down; i <= B + C; i++){
        ll t1 = i - A, t2 = i - B;
        if(t1 > C) t1 = C;
        if(t2 > B) t2 = B;
        t2 = i - t2;
        ll tt = min(i - C, D - C + 1);
        ans += (t1 - t2 + 1) * tt;
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