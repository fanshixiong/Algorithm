## codeforces1312 D. Count the Arrays

### 题目大意：

给定$n, m，$在$1 ~ m $中取 $n$ 个元素，有且只有两个元素相同，将它们排成在最大值左侧严格单增，在最大值右侧严格单减的序列。问这样的序列有多少个？答案对$998244353$取模。

### 解题思路：

首先，我们可以想到 从中选出$n-1$个数字，有$C_{m}^{n-1}$种。然后我们可以让其中一部分的数字重复，但是最大值不能够重复，否则破坏了约束，有$C_{n-2}^{1}$种。除去两个相同元素和最大元素，其余 n - 3 个元素选择若干个降序放到最大值后面，有$C_{n-3}^{0} + C_{n-3}^{1} + C_{n-3}^{2} + ... + C_{n-3}^{n-3} = 2^{n-3}$。

**注：**$n=2$和$n-1>m$时要输出$0$。

代码：

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int mod = 998244353;
const int maxn = 2e5 + 10;
ll fact[maxn];

ll qsm(ll a, ll b){
    ll ans = 1;
    a %= mod;
    while(b){
        if(b & 1){
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans % mod;
}


ll comb(int m, int n){
    return 1ll * (fact[m] * qsm((fact[n] * fact[m - n]) % mod, mod - 2)) % mod;
}

void solve(){
    int n, m;
    cin >> n >> m;
    if(n == 2 || n - 1 > m){
        cout << 0 << endl;
        return;
    }
    ll a = comb(m, n - 1) % mod;
    //cout << a << endl;
    ll b = (n - 2) % mod;
    //cout << b << endl;
    ll c = qsm(2, n - 3);
    //cout << c << endl;
    ll ans = (((a * b) % mod) * c) % mod;
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    fact[0] = 1;
    for (int i = 1; i < maxn; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }
    solve();
    return 0;
}
```

