#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    int ans = 0;
    int cnt[26];
    for (int i = 0; i < (k & 1 ? k / 2 + 1 : k / 2); i++){
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; i + j * k < n; j++){
            cnt[s[i + j * k] - 'a']++;
            if(i != k-i-1) cnt[s[k - 1 - i + k * j] - 'a']++;
        }
        sort(cnt, cnt + 26);
        if((k&1) && i == k/2)
            ans += n / k - cnt[25];
        else
            ans += 2 * n / k - cnt[25];
    }
    cout << ans << endl;
}
int main(){
    IOS;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}