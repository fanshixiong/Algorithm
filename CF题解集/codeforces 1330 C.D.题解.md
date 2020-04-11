# codeforces 1330 C.D.题解



### [Dreamoon Likes Coloring](https://codeforces.com/contest/1330/problem/C)

**题意：**给$n<=100000$个待染色的格子，$m$个$l_i$对应$m$次染色过程（$m$种颜色)，第$i$次染色的区间范围为$[p_i, p_i+l_i-1]$ , 其中，$p_i$的值可从区间$[1，n-l_i+1]$中任选。每一个格子最终的颜色为最后一次对其染色的值，要求构造使得每一个格子都被染色且$m$种颜色均出现的染色方案，如果不存在则输出一1。

**题解：**不存在的情况：

1. 所有染色区间的长度之和小于$n$的话是不存在有效方案的（即$\sum_{i=1}^{m}l_i<n$ , 此时$n$个格子无法被全部染色，直接输出一1。
2. 第$i$次染色的时候，$p_i$能够取到的最大值比i小，即$n-l_i+1<i$, 输出-1。

考虑完不存在的情况后，我们从后往前染色，用$suff_i$代表$l_i$的后缀，则当剩余染色格子的数目大于染色的次数$i$时， $p_i = suff_i$; 当等于$i$时， 此时可以刚好将剩余的格子全部染色。

综上: $p_i = max(i, n-suff_i+1)$。

AC：

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 1e5 + 10;
int l[maxn], p[maxn];
void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> l[i];
        if(l[i] > n-i+1){ //无法保证在i染色之前的每个区间都能拥有至少一个独立的位置
            cout << -1 << endl;
            return;
        }
    }
    l[n + 1] = 0;
    for (int i = m; i >= 1; i--) l[i] += l[i+1];

    if(l[1] < n){ //不能全部上色
        cout << -1 << endl;
        return;
    }
    /*当剩余的染色格子数目大于剩余染色的次数i时，p[i]=suff[i]；
    当等于i时，这个时候刚好可以每一次将左端点向左扩展一位而实现剩余全部格子的染色。
    即p[i] = max(i, n−suff[i]+1)*/
    for (int i = m; i >= 1; i--) p[i] = max(i, n-l[i]+1);

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
```



### [Dreamoon Likes Sequences](http://codeforces.com/contest/1330/problem/D)

**题意：**给出两个数$d, m$, 构造一个升序序列$a_i$, 使得按照构造方式构造的$b_i$也是升序，问构造方案数。

构造方式：$b_1 = a_1, b_i = b_{i-1}\  xor\ a_i$ 。

**题解：**规律：每个划分$i$，对应的$b_i$的最高位的$1$比$b_{i-1}$的最高位的$1$要高一位。如：

​	$ \{1\}\{2,3\}\{4,5,6,7\}\{8,9,10,11,12,13,14,15\}$ ， 

注意边界$i$的取值：$min(d, 2^i - 2^{i-1})$

AC:

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
void solve(){
    ll n, m;
    cin >> n >> m;
    ll ans = 1, i = 1;
    while((1 << (i-1))-1 <= n){
        ll t = min(n, (ll)((1 << i) - 1)) - ((1 << (i - 1)) - 1);
        ans = (ans * (t + 1)) % m;
        i++;
    }
    cout << (ans - 1 + m) % m << endl;
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
```

