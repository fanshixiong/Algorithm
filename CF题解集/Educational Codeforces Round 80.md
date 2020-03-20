# Educational Codeforces Round 80

比赛链接：

[Educational Codeforces Round 80](https://codeforces.com/contest/1288)



### A-Deadline

由 $ x + \frac{d}{x + 1} = (x + 1) + \frac{d}{(x + 1)} - 1$ ， $f(x) = x + \frac{d}{x + 1}$得 $ f(x_0) = 2 \sqrt{d} - 1 $.

所以我们只需要枚举$0 $到 $\left\lceil \sqrt{d} \right\rceil$即可。

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+7;
ll p[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        int ma = sqrt(d) + 10, i;
        for (i = 0; i < ma; i++){
            if(i + (d+i)/(i+1) <= n)
                break;
        }
        cout << (i < ma ? "YES" : "NO") << endl;
    }
    return 0;
}
```



### B - Yet Another Meme Problem

由题：

$ a \cdot b + a + b = conc(a, b) $

$a \cdot b + a + b = a \cdot 10^{|b|} + b$

$a \cdot b + a = a \cdot 10^{|b|}$

$b + 1 = 10^{|b|}$

答案是 $a * (|b + 1| - 1)$

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+7;
ll p[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        ll a, b, cnt=0;
        cin >> a >> b;
        b++;
        while(b){
            cnt++;
            b /= 10;
        }
        ll ans = a * (cnt - 1);
        cout << ans << endl;
    }
    return 0;
}
```



## C - Two Arrays

由题目知道 ：

$a_1, a_2, \dots, a_m, b_m, b_{m-1}, \dots , b_1$

这是一个非递减序列。

这题有个有趣的数学知识，用到了搁板法，意思就是从$n$个数中取$2m$个有多少种取法。

还有$c$++必须用逆元来做，否则会输出$0$.

用其他语言应该可以直接求C。

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 10005;
ll fac[maxn];


ll qpow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1){
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
ll C(ll m, ll n){
    if(m>n || m <0)
        return 0;
    ll f1 = fac[n], f2 = fac[m] * fac[n - m] % mod;
    return f1 * qpow(f2, mod - 2) % mod;
}
int main(){
    ios_base::sync_with_stdio(0);
    fac[0] = 1;
    for (int i = 1; i < maxn; i++)
        fac[i] = fac[i - 1] * i % mod;
    ll n, m;
    cin >> n >> m;
    ll ans = C(n - 1, 2 * m + n - 1) % mod;
    cout << ans << endl;
    return 0;
}const int N = 1e3 + 7, M = 13;
int n, m;
modint f[M][N], ans;

int main() {
    rd(n), rd(m);
    f[0][1] = 1;
    for (int i = 0; i < m; i++)
        for (int j = 1; j <= n; j++)
            for (int k = j; k <= n; k++)
                f[i+1][k] += f[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            ans += f[m][i] * f[m][n-j+1];
    print(ans);
    return 0;
}
```



## D - Minimax Problem

二分。

题目的讲解[卿学姐](https://space.bilibili.com/611212?spm_id_from=333.788.b_765f7570696e666f.1)实在是良心。



```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5+7;
int n, m, ans_l, ans_r;
int num[1000];
int a[maxn][11];

bool judge(int mid){
    memset(num, 0, sizeof(num));
    for (int i = 0; i < n; i++){
        int x = 0;
        for (int j = 0; j < m; j++){
            if(a[i][j] >= mid)
                x += (1 << j);
        }
        num[x] = i + 1;
    }
    for (int i = 0; i < (1 << m); i++){
        for (int j = 0; j < (1 << m); j++){
            if(num[i] && num[j] && ((i|j) == ((1<<m)-1))){
                ans_l = num[i];
                ans_r = num[j];
                return true;
            }
        }
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    int l = -1, r = 1e9;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
            l = min(l, a[i][j]);
            r = max(r, a[i][j]);
        }
    }

    int ans = l;
    while(l<=r){
        int mid = (l + r) >> 1;
        if(judge(mid)){
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    judge(ans);
    cout << ans_l << " " << ans_r << endl;
    return 0;
}
```





## E - Messenger Simulator

树状数组。

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e6+7;

int bit[maxn], a[maxn], max_a[maxn], min_a[maxn];
int pos[maxn];
int n, m;

int lowbit(int x){
    return x & (-x);
}

void update(int x, int op){
    while(x < maxn){
        bit[x] += op;
        x += lowbit(x);
    }
}
int get(int x){
    int ans=0;
    while(x){
        ans += bit[x];
        x -= lowbit(x);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    memset(bit, 0, sizeof(bit));
    for (int i = 1; i<=n; i++){
        max_a[i] = min_a[i] = i;
        pos[i] = i + m;
        update(i+m, 1);
    }
    for (int i = 0; i<m; i++){
        int x;
        cin >> x;
        min_a[x] = 1;
        max_a[x] = max(max_a[x], get(pos[x]));

        update(pos[x], -1);
        pos[x] = m - i;
        update(pos[x], 1);
    }
    for (int i = 1; i<=n; i++){
        max_a[i] = max(max_a[i], get(pos[i]));
    }
    for (int i = 1; i <= n; i++){
        cout << min_a[i] << " " << max_a[i] << endl;
    }
        return 0;
}
```

