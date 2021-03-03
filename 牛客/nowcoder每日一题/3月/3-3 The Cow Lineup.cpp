#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const ll mod = 1e9+7;
ll b, m, n, k;
int a[maxn];
void solve(){
    cin >> n >> k;
    memset(a, 0, sizeof a);

    int num = 0, ans = 1;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(!a[x]) num++;
        if(num == k){
            num = 0;
            ans++;
            memset(a, 0, sizeof a);
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