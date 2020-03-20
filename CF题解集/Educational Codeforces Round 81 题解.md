# Educational Codeforces Round 81 题解

### [A - Display The Number](https://codeforces.com/contest/1295/problem/A)

肯定是1越多越好，因为位数越大越大，所以当n是2的倍数的时候，全是1

但是n可能不是n的倍数，此时应该有$（ n - 3 ） /  2 $个$1$和$1$个$7$，并且7在前面

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int maxn = 2e5 + 10;
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt = n >> 1;
        if(n & 1){
            cout << 7;
            cnt--;
        }
        while(cnt--){
            cout << 1;
        }
        cout << endl;
    }
    return 0;
}
```



---



### [B - Infinite Prefixes](https://codeforces.com/contest/1295/problem/B)

本题有几点需要注意

1.如果所给$x$是0，要特判空字符串情况，也就是$sum$初始为1，其他为0

2.循环的题目第一看循环节，我们知道题目不是求在哪个位置相等，而是求个数，所以只需要考虑第一节

3.分两种情况，因为要排除无穷的情况，假如一个循环节内1的个数和0的相等，那么我们就需要遍历一下这个循环节，如果存在满足x的，那么一定有无穷个，否则是0个。

4.个数不相同的情况，那么我们可以想到，假设一个循环节差$delta$，满足条件的情况肯定时t的倍数加上最后一个循环节中的部分差$cur$等于x

也就是说   $(x - cur) \% delta == 0$，找到一个这样的情况 $ans++$，但是要注意的是，两者必须是同号的，因为模数为0两者不一定同号，如果不同号则没有意义，是相反的。

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;
bool judge(int cur, int delta){
    if(delta < 0){
        delta = -delta;
        cur = -cur;
    }
    if(cur < 0)
        return false;
    return cur % delta == 0;
}
void solve(){
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    int delta = 0;
    for (int i = 0; i < n; i++){
        if(s[i] == '0')
            delta++;
        else
            delta--;
    }
    int cur = 0, ans = 0;
    
    for (int i = 0; i < n; i++){
        if(delta == 0 && cur == x){
            cout << -1 << endl;
            return;
        }
        if(delta != 0 && judge(x-cur, delta))
            ans++;
        if(s[i]=='0')
            cur++;
        else
            cur--;
    }
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```





---



### [C - Obtain The String](https://codeforces.com/contest/1295/problem/C)

本题是暴力题，思路很好想，只需要设计一个指针遍历t字符串，答案不存在只有可能是t中字符串s中没有

然后不停映射s就行，如果t中连续的子串不是s中的递增的，那么就要ans++；

问题是实现方法，要是纯暴力的搜，一定会TLE，所以要想一个巧妙的解法：

设置$nxt$数组，代表$t$字符串在当前的$i$字符位上下一个字符$c$在字符串$s$的向后最早出现的位置是什么。

具体看代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;

int nxt[maxn][26];
void solve(){
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int vis[26];
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < m; i++){
        vis[t[i] - 'a'] = 1;
    }
    for (int i = 0; i < n; i++){
        vis[s[i] - 'a'] = 0;
    }
    for (int i = 0; i < 26; i++){
        if(vis[i]){
            cout << -1 << endl;
            return;
        }
    }

    //initial
    for (int i = 0; i < 26; i++)
        nxt[n][i] = -1;
    for (int i = n - 1; i >= 0; i--){
        for (int c = 0; c < 26; c++){
            nxt[i][c] = nxt[i + 1][c]; //向前回溯
        }
        nxt[i][s[i] - 'a'] = i; //字符串s中从第i个字符处开始往后找，第s[i]-'a'字符最早出现的位置是i
    }
    int cur = 0, ans = 1;
    for (int i = 0; i < m; i++){
        cur = nxt[cur][t[i] - 'a'];
        if(cur == -1){
            ans++;
            cur = 0;
            i--;
        }
        else{
            cur++;
        }
    }
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```





### [D - Same GCDs](https://codeforces.com/contest/1295/problem/D)



题意很明显要求出当$k∈[a,a+m),gcd=gcd(a,m)$时，满足$gcd(k,m)=gcd$的$k$的个数，由欧拉函数可以转换为$gcd(k/gcd,m/gcd)=1,k∈[a,a+m)$，$a$和$m$肯定是$gcd$的倍数，那么假设$a=x∗gcd,m=y∗gcd$，令$i=k/gcd$，那么$i$的取值范围为$[x,x+y)$，那么最终要求的东西就是当$i∈[x,x+y)$时，满足$gcd(i,y)=1$的$i$的个数。

把$i∈[x,x+y)$，分成两个区域$[x,y]$和$(y,x+y)$

先讨论$i∈(y,x+y)$时，由欧几里得定理可以得出$gcd(i,y)=gcd(y,i%y)=gcd(i%y,y)$，再由$i∈(y,x+y)$可以化简所求东西为求$i∈(0,x)$时，满足$gcd(i,y)$的$i$的个数，而我们把这个区间与$[x,y]$进行合并，就可以发现，我们要求的就是$i∈[1,y]$时满足$gcd(i,y)=1$的个数，即$i$与$y$互质，可以发现求的就是$y$的欧拉函数值。

代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;
ll phi(ll x){
    ll ans = x;
    for (ll i = 2; i * i <= x; i++){
        if(x % i == 0){
            ans -= ans / i;
            while(x % i == 0)
                x /= i;
        }
    }
    if(x > 1)
        ans -= ans / x;
    return ans;
}
void solve(){
    ll a, m;
    cin >> a >> m;
    cout << phi(m / __gcd(a, m)) << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```





----



### 欧拉函数

>
>
>#### 欧拉函数：
>
>欧拉函数，即$φ(n)$，表示的是小于等于$n$和$n$互质的数的个数。
>
>比如$φ(1)=1$。
>
>利用唯一分解定理，我们可以把一个整数唯一地分解为质数幂次的乘积，
>
>设
>
>$n=p_1^{k_1}p_2^{k_2}...p_s^{k_s}$，其中$p_i$是质数，那么$\varphi(n)=n\times\prod_{i=1}^s\frac{p_i-1}{p_i}$
>
>```cpp
>int phi(int n){
>    int ans = n;
>    for(int i = 2; i * i <= n; ++i){
>        if(n % i == 0){
>            ans -= ans * i;
>            while(n % i == 0) 
>                n /= i;
>        }
>    }
>    if( n > 1 ) 
>        ans -= ans * i;
>    return ans;
>}
>```
>
>#### 欧拉函数的性质：
>
>①欧拉函数是积性函数：
>
>如果有$gcd(a,b)=1$，那么$φ(a×b)=φ(a)×φ(b)$
>
>特别的，当$n$为奇数时，$φ(2n)=φ(n)$
>
>②$n=\sum_{d|n}\varphi(d)$
>
>即表示，$n$的所有因子的欧拉函数的值加起来为$n$
>
>③如果$gcd(k,n)=d$, 那么$gcd(k / d, n / d)=1$
>
>④设$f(x)$为$gcd(k,n)=x　(k<n)$ 的 $ k$ 的个数，那么$n=\sum_{i=1}^n f(i)$
>
>⑤若$n=p^k$，其中$p$为质数，那么$\varphi(n)=p^k-p^{k-1}$



----



### [E - Permutation Separation](https://codeforces.com/contest/1295/problem/E)

在区间$[1,n−1]$枚举切割位置$i$ (从$p[i]$ 右边切开，不取$n$是因为要保证两部分初始非空) ，时间复杂度$O(n)$

那么我们知道所有$p[i]$ 位置后面的小于等于 $i$ 的数都要移动到左边，$p[i]$ 位置即前面的大于 $i$ 的数都要移动到右边。

我们尚若可以$O(log n)$ 时间内得到上面移动操作的$cost$就可以维护出最小值。

想到了线段树。

首先对$a[i]$ 做一个前缀和 数组 $sum[i]$ ，代表将1~i的数都移动到右边需要的cost。

以$sum[i] $数组建立区间修改，区间查询最小值的线段树。

然后从$1$到$n-1$枚举割切位置$i$，

对于第$i$个位置，我们将找到$i$在$p$中的位置 id ,将区间$[1,id−1]$减去 $a[id]$，区间$[id,n−1]$ 加上$a[id]$

意义为：在切割位置大于等于i 的时候，不需要将数字i移动到右边部分，又结合线段树维护的是前缀和数组，

那么对于每一个位置i 用线段树的根节点维护的最小值去更新答案ans即可。

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5 + 10;

struct node{
    int l, r;
    ll laze, val;
} segment_tree[maxn << 2];

int n, p[maxn], id[maxn];
ll a[maxn], sum[maxn];

void push_Up(int rt){
    segment_tree[rt].val = min(segment_tree[rt << 1].val, segment_tree[rt << 1 | 1].val);
}

void build(int rt, int l, int r){
    segment_tree[rt].l = l;
    segment_tree[rt].r = r;
    if (l == r){
        segment_tree[rt].val = sum[l];
        segment_tree[rt].laze = 0ll;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_Up(rt);
}

void push_Down(int rt){
    segment_tree[rt << 1 | 1].val += segment_tree[rt].laze;
    segment_tree[rt << 1 | 1].laze += segment_tree[rt].laze;
    segment_tree[rt << 1].val += segment_tree[rt].laze;
    segment_tree[rt << 1].laze += segment_tree[rt].laze;
    segment_tree[rt].laze = 0;
}

void update(int rt, int l, int r, int num){
    if(segment_tree[rt].laze && l != r)
        push_Down(rt);
    if(segment_tree[rt].l >= l && segment_tree[rt].r <= r){
        segment_tree[rt].val += num;
        segment_tree[rt].laze += num;
        return;
    }
    int mid = segment_tree[rt].l + segment_tree[rt].r >> 1;
    if(r > mid){
        update(rt << 1 | 1, l, r, num);
    }
    if(l <= mid){
        update(rt << 1, l, r, num);
    }
    push_Up(rt);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> p[i];
        id[p[i]] = i;
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    ll ans = a[n];
    build(1, 1, n - 1);
    ans = min(ans, segment_tree[1].val);
    int x;
    for (int i = 1; i <= n; i++){
        x = id[i];
        if(x != n){
            update(1, x, n - 1, -a[x]);
        }
        if(x != 1){
            update(1, 1, x - 1, a[x]);
        }
        ans = min(ans, segment_tree[1].val);
        //cout << ans << "  ";
    }
    cout << ans << endl;
    return 0;
}
```

