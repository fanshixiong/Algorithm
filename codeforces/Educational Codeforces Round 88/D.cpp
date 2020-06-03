#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];
void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];

    int ans = 0;
    for (int x = 1; x <= 30; x++){
        int sum = 0;
        for (int i = 0; i < n; i++){
            if(a[i] > x) continue;
            sum += a[i];
            if(sum < 0) sum = 0;
            else ans = max(ans, sum - x);
        } 
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