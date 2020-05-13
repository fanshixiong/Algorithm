#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int m[maxn], c[maxn], cnt[maxn], suf[maxn];
vector<int> res[maxn];

void solve(){
    memset(cnt, 0, sizeof cnt);
    memset(suf, 0, sizeof suf);
    int n, k; cin >> n >> k;
    for (int i = 0; i <= n; i++) res[i].clear();

    for (int i = 1; i <= n; i++)    cin >> m[i], cnt[m[i]]++;
    sort(m + 1, m + 1 + n);

    for (int i = 1; i <= k; i++) cin >> c[i];
    for (int i = k; i >= 1; i--) suf[i] = suf[i+1] + cnt[i];
    int ans = 0;
    for (int i = 1; i <= k; i++){
        int t = ceil(1.0 * suf[i] / c[i]);
        ans = max(ans, t);
    }
    int num = 1;
    for (int i = 1; i <= n; i++){
        res[num].push_back(m[i]);
        num++;
        if(num > ans) num = 1;
    }
    cout << ans << endl;
    for (int i = 1; i <= ans; i++){
        vector<int> v = res[i];
        cout << v.size() << " ";
        for(auto x : v) cout << x << " ";
        cout << endl;
    }
    //cout << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}