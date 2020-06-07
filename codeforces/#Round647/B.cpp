#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];
void solve(){
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) cin >> a[i];
    if(n % 2){
        cout << -1 << endl;
        return;
    }
    int cnt[1200];
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            cnt[a[i] ^ a[j]]++;
        }
    }
    for (int i = 0; i < 1025; i++){
        if(cnt[i] == n/2){
            cout << i <<endl;
            return;
        }
    }
    cout << -1 << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}