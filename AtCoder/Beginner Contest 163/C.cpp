#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn], cnt[maxn];
void solve(){
    memset(cnt, 0, sizeof cnt);
    int n; cin >> n;
    for(int i = 1; i < n; i++) cin >> a[i];

    for(int i = 1; i < n; i++) cnt[a[i]]++;

    for(int i = 1; i <= n; i++) cout << cnt[i] << endl;
}
int main(){
    IOS;
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}