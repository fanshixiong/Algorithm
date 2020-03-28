## [Educational Codeforces Round 84](https://codeforces.com/contest/1327) 题解



### A-[Sum of Odd Integers](https://codeforces.com/contest/1327/problem/A)

**题意：** $n$是否能表示为 $k$个不同的正奇数之和?

**题解：**$k$个不同不同的正奇数之和最小值为$k^2$ ，故仅当 $n >= k^2$ 且两数奇偶性相同时满足条件。要开long long不然wa.

代码：

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n, k;
    cin >> n >> k;
    if((n-1) / 2 + 1 < k ||  k * k > n){
        cout << "NO" << endl;
        return;
    }
    if(k % 2 == n % 2){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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



### B-[Princesses and Princes](https://codeforces.com/contest/1327/problem/B)

**题意：**有 $n$ 个女儿和  $n$  个王子，每个女儿有可匹配的王子的列表  $g_i[1], g_i[2], ……, g_i[k]$  （单增）。从  $1$ 号女儿开始，将每个女儿匹配给她的列表里尚未匹配的最小号的王子。问是否能向一位女儿的列表里增加一位王子使得总共匹配成功的对数增加。

**题解：**把一个没匹配上的女儿和（全都匹配之后剩下的）最小号的王子匹配上。

**代码：**

```cpp
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int vis[maxn], x[maxn];
void solve(){
    int n; cin >> n;
    for (int i = 0; i <= n; i++){
        vis[i] = x[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int v; cin >> v;
            if (!x[i] && !vis[v]) {
                x[i] = v, vis[v] = 1;
            }
        }
    }
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++){
        if(!x[i]){
            a = i; break;
        }
    }
    for (int i = 1; i <= n; i++){
        if(!vis[i]){
            b = i; break;
        }
    }
    if(a || b){
        cout << "IMPROVE" << endl;
        cout << a << " " << b << endl;
    }
    else{
        cout << "OPTIMAL" << endl;
    }
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

### C-[Game with Chips](https://codeforces.com/contest/1327/problem/C)

**题意：** $n$ * m  的棋盘上有  $k$ 个棋子，每个棋子坐标 $sx_i, sy_i$  ，目的地 $fx_i, fy_i$ .

对于路线上的每一步L/R/U/D，使**所有棋子**向该方向移动一格，如果已经到达边界则不动。

问是否能找到一条长度不超过  $2*m*n$  路线使得所有棋子都**经过**其目的地。如果可以，输出路径。

如果不存在，输出  $-1$ 。

**题解：**全挪到左上角然后蛇形走一遍棋盘。

**代码：**

```cpp
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i){
        int x, y; cin >> x >> y;
    }
    for(int i = 1; i <= k; ++i){
        int x, y; cin >> x >> y;
    }
    string s = "";
    s += string(n - 1, 'U');
    s += string(m - 1, 'L');     
    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            s += string(m - 1, 'R');
        }
        else {
            s += string(m - 1, 'L');
        }
        if (i < n)
            s += "D";
    }
    cout << s.size() << endl;
    cout << s << endl;
    return 0;
}
```



### D-[Infinite Path](https://codeforces.com/contest/1327/problem/D)

**题意：**给定一个排列和排列上面每一个点的颜色。定义排列乘法 $c=a×b→c[i]=b[a[i]]$, 定义排列的幂.

定义无穷环：p[p[…]]=p[i]p[p[…]]=p[i] （禁止套娃）

求是否有一个无穷环的 $k$ 次幂使得 环上的点的颜色都相等。

**题解：**对排列的每个初始的闭环进行处理，处理一个闭环时枚举$k$从$1$到$m-1$，当$m%(k+1)==0$时遍历所有产生的小闭环看是否颜色一样，取最小值即可。

**代码：**

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int q[maxn], p[maxn], c[maxn], vis[maxn];

int func(int cnt){
    for (int i = 1; i <= cnt; i++){
        if(cnt % i != 0) continue;
        for (int j = 0; j < i; j ++){
            int t = q[j];
            for (int x = j; x < cnt; x += i){
                if(q[x] != t) t = 0;
            }
            if(t) return i;
        }
    }
    return -1;
}
void solve(){
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> c[i];
    }
    for (int i = 0; i <= n; i++){
        vis[i] = 0;
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++){
        if(vis[i]) continue;
        int cnt = 0, t = i;
        while(!vis[t]){
            q[cnt++] = c[t];
            vis[t] = 1;
            t = p[t];
        }
        ans = min(ans, func(cnt));
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

### E-[Count The Blocks](https://codeforces.com/contest/1327/problem/E)

**题意：**输入一个$n < 2 * 10 ^ 5$。长度为 $k$ 的数段定义为一个数串中**恰好连续 **$k$个相同的数。

输出 $n$ 个数，第 $i$个数为  $n$位数（含前导 $0$） $000...0$到$999...9$ 之间的所有数中，长度为$i$ 的数段的数量之和， 对 $998244353$ 取模。

**题解：**找规律，$F_{i−1}=10*F_i+81*10^{n−i−1}, i<n−1$

**代码：**

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 998244353;
const int maxn = 2e5 + 10;

ll ans[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    ll x = 810;
    ans[1] = 10; ans[2] = 180;
    for (int i = 3; i < maxn; i++){
        ans[i] = (ans[i - 1] * 10 + x) % mod;
        x = (x * 10) % mod;
    }
    for (int i = n; i >= 1; i--){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
```