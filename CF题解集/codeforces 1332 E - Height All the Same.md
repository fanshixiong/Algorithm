## codeforces 1332 [E - Height All the Same](https://codeforces.com/contest/1332/problem/E)(组合数学、奇偶性)



#### 题意：

现在有一个$n∗m$的方格，第$i$行第$j$列有$a[i][j]$个方块。

你可以执行以下操作任意次：

1、选择$(i,j)$使$a[i][j]$加上$2$。

2、选择两个相邻的方格，将其方格数加上$1$。

现在问初始$a[i][j]$可以是$[L,R]$中的任意数，有多少种初始方案可以通过任意次数的操作后使所有的$a[i][j]$相等。

#### 思路：

因为操作1不改变奇偶性，而同奇偶性的数一定可以通过操作1变成相等的数，所以对于一个$n∗m$的方格，只考虑其奇偶性，问题可以转化为，能否选择两个相邻的方格，使其奇偶性翻转，最后使整个方格奇偶性一致。

**这是一个经典的问题，解法为：奇数和偶数的个数都是奇数是不行的，否则可行。**

可以观看下图，红色代表奇数，白色代表偶数。

![img](https://img2020.cnblogs.com/blog/1578720/202004/1578720-20200401180950188-1269671428.png)

我们可以通过一次翻转使其变成：

![img](https://img2020.cnblogs.com/blog/1578720/202004/1578720-20200401181057397-519246541.png)

当将奇数移动到一些特殊的位置后，有因为剩下的偶数的个数cntcnt为偶数，可以通过cnt/2cnt/2次翻转操作变为：

![img](https://img2020.cnblogs.com/blog/1578720/202004/1578720-20200401181337016-827456088.png)

全部变成红色（奇数）。

**只要奇数的个数和偶数个数的至少一个为偶数，就可以通过这种方法将其变成同奇偶性。**

来思考本题的2种情况：

如果$n∗m$是奇数，那么奇数的个数和偶数个数至少一个为偶数，则所有初始状态都满足条件。

答案为$(R−L+1)^{n∗m}$。

否则，设$x$为$[L,R]$中奇数的个数，设$y$为$[L,R]$中偶数的个数。

$ans=∑^{n∗m}_{i=0}C^i_{n∗m}∗x^i∗y^{n∗m−i},i\% 2 = 0$

那么答案就是$∑^{n∗m}_{i=0}C^i_{n∗m}∗x^i∗y^{n∗m−i}$二项式中偶数项的和。

构造二项式$(x−y)^{n∗m}=∑^{n∗m}_{i=0}C^i_{n∗m}∗x^i∗y^{n∗m−i}∗(−1)^{n∗m−i},(−1)^{n∗m−i}=(−1)^i$的奇偶项为正负交替的。

则：

$ans=\frac{(x+y)^{n*m}+(x-y)^{n*m}}{2}$

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
const int mod = 998244353;
ll qpow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1)  ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans % mod;
}
void solve(){
    ll n, m, l, r;
    cin >> n >> m >> l >> r;
    ll x = (r - l + 1);
    if(n * m % 2 == 1){
        cout << qpow(x, n * m) % mod << endl;
        return;
    }
    //cout << x << " " << n * m << endl;
    ll ans = (qpow(x, n * m) + ((x & 1) ? 1 : 0)) % mod;
    //cout << ans << endl;   
    ans = (ans * qpow(2ll, mod - 2ll)) % mod; //①
    cout << ans << endl;
}
int main(){
    IOS;
    int t; t = 1;
    while(t--){
        solve();
    }
    return 0;
}
```



参考：

1. 本文转载自：[qieqiemin](https://www.cnblogs.com/qieqiemin/p/12614527.html)。
2. 不懂①可以转[codeforce#Round604 -E Beautiful Mirrors](https://www.cnblogs.com/fans-fan/articles/12053818.html)
3. ①应用可转：[codeforces1312 D. Count the Arrays](https://www.cnblogs.com/fans-fan/articles/12519180.html)

