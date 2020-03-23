#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 2e5 + 10;
const int mod = 998244353;
pair<int, int> p[maxn];
int cnt[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p + 1, p + 1 + n);
    ll sum = 0, ans = 1;
    for (int i = n; i > n - k; i--){
        cnt[n - i + 1] = p[i].second;
        sum += p[i].first;
    }
    sort(cnt + 1, cnt + 1 + k);
    for (int i = 2; i <= k; i++){
        ans = (ans * (cnt[i] - cnt[i - 1])) % mod;
    }
    cout << sum << " " << ans << endl;
    return 0;
}