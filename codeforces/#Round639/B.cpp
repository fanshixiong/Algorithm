#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
ll f[maxn];
void solve(){
    int n; cin >> n;
    int cnt = 0;
    while(n >= 2){
        int x = lower_bound(f + 1, f + 100000, n) - f;
        //cout << f[x] << " ";
        if(f[x] == n){
            cnt++;
            break;
        }
        cnt++;
        n -= f[x - 1];
    }
    cout << cnt << endl;
}
int main(){
    IOS; int t; cin >> t;
    f[1] = 2;
    for (int i = 2; i < 100000; i++){
        f[i] += f[i - 1] + 2 * i + i - 1;
    }
    while(t--){
        solve();
    }
    return 0;
}
/*
1
24
*/