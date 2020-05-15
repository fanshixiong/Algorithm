/*
    数论：
    对于某个质因子 p 而言：
    如果 p 在 n 个数中均出现过，那么找到指数的次小值 k，其贡献就是 p ^ k
    如果 p 在 n - 1 个数中均出现过，那么找到指数的最小值 k，其贡献就是 p ^ k
    如果 p 在 n 个数中的出现次数小于 n - 1 ，其贡献为 1
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 100;
int a[maxn];
void solve(){
    int n, k; cin >> n >> k;
    bool flg = true;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == k) flg = false;
    }
    if(flg){ cout << "no" << endl; return;}

    for (int i = 1; i < n; i++){
        if(a[i] >= k){
            if(a[i+1] >= k || (i+2<=n && a[i+2] >= k)){
                flg = true;
                break;
            }
        }
    }
    if(n == 1 || flg) cout << "yes" << endl;
    else cout << "no" << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}