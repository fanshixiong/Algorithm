#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];
void solve(){
    int n; cin >> n;
    bool flg = true;
    if(n <= 1) flg = false;
    map<int, int> p;
    p.clear();
    int cnt = 0, maxx = -1;
    map<int, int> vis;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if(!p[a[i]]) cnt++;
        p[a[i]]++;
        maxx = max(p[a[i]], maxx);
    }
    //cout << cntup << " " << cnt << " " << maxx<< endl;
    int ans = min(cnt, maxx);
    if(cnt == maxx) ans --;
    
    if(!flg)  cout << 0 << endl; 
    else cout << ans << endl;
    
}
int main(){
    //freopen("Cin.txt", "r", stdin);
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}