
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int n, a, r, m;
int h[maxn];
void solve(){
    cin >> n >> a >> r >> m;
    m = min(m, a + r);  //去掉再加上的代价比
    for (int i = 1; i <= n; i++) cin >> h[i];
    //枚举最低点
    auto f = [&](int x) {
        ll less = 0, more = 0;
        for (int i = 1; i <= n; i++){
            if(h[i] < x) less += x - h[i];
            if(h[i] > x) more += h[i] - x;
        }
        ll minn = min(less, more);
        return minn * m + (less - minn) * a + (more - minn) * r;
    };
    //三分
    int l = 0, r = inf, lmid, rmid;
    while(l < r){
        lmid = l + ((r - l) / 3);
        rmid = r - ((r - l) / 3);    
        if(f(lmid) < f(rmid)){
            r = rmid - 1;
        }else l = lmid + 1;
    }
    cout << f(l) << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}