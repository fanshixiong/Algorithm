/*
https://www.cnblogs.com/stelayuri/p/12903245.html
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 1e6 + 5;
int cnt[maxn];
void solve(){
    //memset(cnt, 0, sizeof cnt);
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    //差分：
    for (int i = A; i <= B; i++){
        cnt[i + B]++;
        cnt[i + C + 1]--;
    }
    for (int i = 1; i < maxn; i++){
        cnt[i] += cnt[i - 1];
    }
    ll ans = 0;
    for (int i = C + 1; i < maxn; i++){
        int val = min(i - 1, D) - C + 1;
        ans += 1ll * val * cnt[i];
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