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
vector<int> p[maxn];


void init(int n){
    for (int i = 2; i * i <= n; i++){
        if(n % i != 0) continue;
        int cnt = 0;
        while(n % i == 0){
            cnt++;
            n /= i;
        }
        p[i].push_back(cnt);
    }
    if(n != 1) p[n].push_back(1);
}

ll qpow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
void solve(){
    int n ; cin >> n ;
    
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        init(x);
    }
    ll ans = 1;
    for (int i = 2; i < maxn; i++){  //枚举质因数
        sort(p[i].begin(), p[i].end());
        if(p[i].size() == n){        //在n个数中出现
            ans *= qpow(i, p[i][1]);
        }
        if(p[i].size() == n-1)  //在n-1个数中出现
            //ans *= pow(i, *min_element(p[i].begin(), p[i].end()));
            ans *= qpow(i, p[i][0]);
        //否则对答案没有贡献
    }
    cout << ans << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}