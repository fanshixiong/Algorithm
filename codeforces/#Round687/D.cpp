#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 3e5 + 10;
int a[maxn], b[maxn];
void solve(){
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    if(n > 60) {
        // 1e9个数有30位2进制，那么2*30 = 60个数一定有三个高位一致的数，两个较小的数异或一定大于较大的数
        cout << 1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++) b[i] = b[i-1] ^ a[i];

    int ans = 1e9;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 60 && i - j > 0; j++)
            for (int k = 0; k <= 60 && i + k < n; k++)
                if ((b[i] ^ b[i - 1 - j]) > (b[i] ^ b[i + k + 1]))
                    ans = min(ans, k + j);
    if(ans == 1e9)
        ans = -1;
    cout << ans << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}