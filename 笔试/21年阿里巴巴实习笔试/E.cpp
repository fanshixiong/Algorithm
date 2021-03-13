// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>
const int maxn = 1e5 + 10;
int xi[maxn], yi[maxn];
map<pi, int> p;
void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> xi[i] >> yi[i];
        p[{xi[i], yi[i]}]++;
    }
    ll ans = 0;
    for(int i = 1; i <= m; i++){
        if(xi[i] == yi[i]) continue;
        if(p[{xi[i], yi[i]}] && p[{yi[i], xi[i]}]) {
            ans += 1ll * 2;
            p[{xi[i], yi[i]}]--;
        }
        else ans += 1ll;
    }
    cout << ans << endl;
}
int main() {
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}