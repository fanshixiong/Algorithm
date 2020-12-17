#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn], n, x;

bool judge(int x){
    for(int i = x; i <= n; i++) if(a[i] < a[i-1]) return false;

    return true;
}
void solve(){
    cin >> n >> x;
    for (int i = 1; i <= n; i++)cin >> a[i];

    int ans = 0;
    for (int i = 1; i <= n; i++){
        if(a[i] <= x) continue;

        if(judge(i + 1)) break;

        swap(x, a[i]);
        ans ++;
    }
    for(int i = 2; i <= n; i++) if(a[i] < a[i-1]) ans = -1;
    cout << ans << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}