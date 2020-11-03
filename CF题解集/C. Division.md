## codeforces Round680 C. Division 题解



### 题目

Oleg's favorite subjects are History and Math, and his favorite branch of mathematics is division.

To improve his division skills, Oleg came up with $t$ pairs of integers $p_i$ and $q_i$ and for each pair decided to find the **greatest** integer $x_i$, such that:

-   $p_i$ is divisible by $x_i$;
-   $x_i$ is not divisible by $q_i$.

Oleg is really good at division and managed to find all the answers quickly, how about you?



**Input**

The first line contains an integer $t$ $(1≤t≤50)$ — the number of pairs.

Each of the following $t$ lines contains two integers $p_i$ and $q_i$ $(1≤ p_i≤10^{18};  2≤q_i≤10^9) $— the $i-th$ pair of integers.



**Output**

Print $t$ integers: the $i-th$ integer is the largest $x_i$ such that $p_i$ is divisible by $x_i$, but $x_i$ is not divisible by $q_i$.

One can show that there is always at least one value of $x_i$i satisfying the divisibility conditions for the given constraints.

**Example**

**input**

```
3
10 4
12 6
179 822
```

**output**

```
10
4
179
```

**Note**

For the first pair, where $p_1=10$ and $q_1=4$, the answer is $x_1=10$, since it is the greatest divisor of $10$ and $10$ is not divisible by $4$.

For the second pair, where $p_2=12$ and $q_2=6$, note that

-   $12$ is not a valid $x_2$, since $12$ is divisible by $q_2=6$;
-   $6$ is not valid $x_2$ as well: $6$ is also divisible by $q_2=6$.

The next available divisor of $p_2=12$ is $4$, which is the answer, since $4$ is not divisible by $6$.



### 题意

找一个最大的$x$，满足$ p\ \%\ x == 0 \  and\  x\ \%\ q != 0$。



### 思路

 质因数分解

*   $p\ \%\ q\ !=\ 0$， $x = p$
*   $p\ \%\ q\ =\ 0$   , 那么$p$一定包含$q$的所有质因数分解的结果。

举例：

$p = 12\  \  q = 6$
$p = 2^2 * 3^1$       $q = 2^1 +3^1$

要使$p\  \%\ q\ !=\ 0$, 只要使 $p$ 将质因数$2$降幂到$0$(也就是q的质因数$2$的次幂之下)，或者将$3$ 的幂降到$0$。

所以，我们只需要枚举$q$的质因子, 找权值最小的，即为答案。



### 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int ans[maxn];

void solve(){
    ll p, q;
    cin >> p >> q;
    if(p % q) { //p不能被q整除，答案就是p
        cout << p << endl;
        return;
    }
    ll ans = 0;
    for (ll i = 1; i * i <= q; i++){
        if(q % i) continue; // 不是q的因子
        //i 和 q/i 都是因子
        ll t = p;
        if(i != 1){
            while(t % q == 0) t /= i; 
            ans = max(ans, t);
        }
        t = p;
        while(t % q == 0) t /= (q / i);
        ans = max(ans, t);
    }
    cout << ans << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```

