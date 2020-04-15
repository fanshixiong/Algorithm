#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 5e5 + 10;
int ans[maxn];
void solve(){
    int n;  cin >> n;
    for (int i = 0; i <= n; i++) ans[i] = 1;
    for (int i = 2; i <= n; i++){
        for (int j = i + i; j <= n; j += i){
            ans[j] = i;
        }
    }
    sort(ans, ans + n + 1);
    for (int i = 2; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}
int main(){
    IOS;
    int t; t = 1;
    while(t--){
        solve();
    }
    return 0;
}