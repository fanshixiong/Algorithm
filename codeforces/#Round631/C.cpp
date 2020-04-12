#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 1e5 + 10;
ll l[maxn], p[maxn];
void solve(){
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> l[i];
        if(l[i] > n-i+1){ //无法保证在i染色之前的每个区间都能拥有至少一个独立的位置
            cout << -1 << endl;
            return;
        }
    }
    l[m + 1] = 0;
    for (int i = m; i >= 1; i--) l[i] += l[i+1];

    if(l[1] < n){ //不能全部上色
        cout << -1 << endl;
        return;
    }
    /*当剩余的染色格子数目大于剩余染色的次数i时，p[i]=suff[i]；
    当等于i时，这个时候刚好可以每一次将左端点向左扩展一位而实现剩余全部格子的染色。
    即p[i] = max(i, n−suff[i]+1)*/
    for (ll i = m; i >= 1; i--) p[i] = max(i, n-l[i]+1);

    for (int i = 1; i <= m; i++) cout << p[i] << " ";
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