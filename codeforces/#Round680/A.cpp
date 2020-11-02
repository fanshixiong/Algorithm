#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];
void solve(){
    int n; cin >> n;
    vector<int> cnt(101, 0);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        cnt[x]++;
    }
    int ans = -1;
    for (int i = 0; i <= 100; i++){
        if(cnt[i] == 1){
            if(ans == -1) ans = i;
        }
        if(cnt[i] == 0){
            if(ans == -1) ans = i+i;
            else ans += i;
            break;
        }
    }
    cout << ans << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}