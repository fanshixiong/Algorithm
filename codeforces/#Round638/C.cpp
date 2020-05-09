#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn], vis[maxn];
void solve(){
    int n; cin >> n;
    map<int, int> pos;
    pos.clear();
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        vis[i] = 0;
        pos[a[i]] = i;
    }
    vis[n + 1] = 1;
    bool flg = true;
    for (int i = 1; i <= n; i++){
        int p = pos[i];
        vis[p] = 1;
        //从 1 到 n，检查数字 i 是否合理
        //数字 i 的右边一位要么是 i + 1 ，要么是被小于 i 的数字填过
        if(i + 1 == a[p + 1] || vis[p + 1]) continue;
        flg = false;
        break;
    }
    if (flg) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}