## [Codeforces Round #677 (Div. 3)](https://codeforces.com/contest/1433) 题解



### A. Boring Apartments



#### 题目

![image-20201107151813871](F:\c++\Game\CF题解集\Codeforces Round #677 (Div. 3) 题解.assets\image-20201107151813871.png)

#### 题解

简单签到题，直接数，小于这个数的$+10$。



#### 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
int a[maxn];
void solve(){
    ll ans = 0;
    int n; cin >> n;

    int cnt = 0, x = n, c10 = 1;
    while(x){
        x /= 10;
        cnt++;
        c10 *= 10;
    }
    c10 /= 10;
    int t = n / c10;
    // cout << c10 << " " << cnt << " " << t << endl;
    ans += (t - 1) * 10;
    cout << ans + (1 + cnt) * cnt / 2 << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```



### B. Yet Another Bookshelf(思维)



#### 题目

![image-20201107152019326](F:\c++\Game\CF题解集\Codeforces Round #677 (Div. 3) 题解.assets\image-20201107152019326.png)

#### 题意

让书架上所有的书$(a[i] = 1)$ 相邻。每次可以将相邻的一段$1$(可以是$1$个)向左移或者右移。



#### 题解

开始模拟了一遍，但没过，太菜了。

思路：统计每个$1$与其最近$1$之间有多少个$0$。



#### 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 100 + 10;
int a[maxn], b[maxn];
void solve1(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> num;
    for (int i = 0; i < n; i++){
        if(a[i] == 0) num.push_back(0); 
        if(a[i] == 1) {if(i == 0 || a[i-1] == 0) num.push_back(1); }
        // cout << i << " " << a[i] << " " << num.size() << endl;
    }
    // for (auto x : num) cout << x << " "; cout << endl;

    n = num.size();
    int cnt = 0, ans = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) cnt += (num[i] & 1);
    
    if(cnt == 1){
        cout << 0 << endl;  return;
    }

    for (int l = 0; l + cnt - 1 < n; l++){
        int r = l + cnt - 1;
        int res = 0;

        vector<int> c0, c1;
        for (int i = 0; i < n; i++){
            if(i >= l && i <= r) {if(num[i] == 0) c0.push_back(i);}
            else {
                if(num[i] == 1) c1.push_back(i);
            }
        }
        for (int i = 0; i < c1.size(); i++){
            res += abs(c1[i] - c0[i]);
        }
        // cout << l << " " << r << " " << res << endl;
        ans = min(ans, res);
    }

    cout << ans << endl;
}

void solve(){
    int n; cin >> n;
    vector<int> num;
    for (int i = 0; i < n; i++){ 
        cin >> a[i]; 
        if(a[i]) num.push_back(i);
    }

    cout << num.back() - num[0] - 1 - num.size() + 2 << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```



### C. Dominant Piranha（思维）

#### 题目

![image-20201107152608626](F:\c++\Game\CF题解集\Codeforces Round #677 (Div. 3) 题解.assets\image-20201107152608626.png)

#### 题意

水族馆里的食人鱼每次可以吃掉比它小的相邻的食人鱼。求最后的那一个食人鱼最开始的位置。



#### 题解

找最大值。(比B简单？)



#### 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 3e5 + 10;
int a[maxn];
void solve(){
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<pi> num;
    for (int i = 1; i <= n; i++){
        if(i > 1 && a[i] > a[i-1]) num.push_back({a[i], i});
        if(i < n && a[i] > a[i+1]) num.push_back({a[i], i});
    }

    int pos = -1;
    for (auto p : num){
        if(pos == -1) pos = p.second;
        else if(a[pos] < p.first) pos = p.second;
    }
    cout << (pos == -1 ? -1 : pos) << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```



### D. Districts Connection(简单构造)



#### 题目

![image-20201107152827345](F:\c++\Game\CF题解集\Codeforces Round #677 (Div. 3) 题解.assets\image-20201107152827345.png)

#### 题意

要在$n$个点建建立$n-1$ 条边，使$ n $个点联通（直接或者间接）。但是相同的帮派间不可以建边，构造出一个可行的方案。

#### 题解

*   当只有$ 1 $个帮派的时候，连接$n$个顶点是不可能的。

*    我们可以选一个帮派，记为$gang1$，将其中一个点和其他的每一个点连接。这样保证这个点与不是帮派$gang1$的所有的点联通。 再将帮派$gang1$的其他点与不在帮派$gang1$的任一点连接，这样构造保证所有的点互相联通。

#### 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 5e3 + 10;
int a[maxn];
void solve(){
    int n; cin >> n;
    unordered_map<int, vector<int>> p;
    for (int i = 0; i < n; i++){ 
        cin >> a[i];
        p[a[i]].push_back(i + 1);
    }

    if((int)p[a[0]].size() == n){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int pos = a[0];
    for(auto x : p){
        if(x.first == pos) continue;
        for(auto c : x.second) cout << 1 << " " << c << endl;
    }
    for(auto x : p){
        if(x.first != a[0]){
            pos = x.first;
            break;
        }
    }

    vector<int> t = p[a[0]];
    int q = p[pos][0];
    // cout << "at: " << pos << " " << t.size() << " " << q << endl;
    for (int i = 1; i < (int)t.size(); i++){
        cout << q << " " << t[i] << endl;
    }
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```



### E. Two Round Dances

#### 题目



![image-20201107153552570](F:\c++\Game\CF题解集\Codeforces Round #677 (Div. 3) 题解.assets\image-20201107153552570.png)



#### 题解

( 在oeis网上输入$12164510040883200$ 就明白了。)

圆排列。



#### 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 3e5 + 10;
int a[maxn], dp[maxn];
void solve(){
    int n; cin >> n;
    if(n <= 4){
        cout << (n == 2 ? 1 : 3) << endl;
        return;
    }
    n /= 2; n-=1;
    ll ans = 1;
    for (int i = 1; i <= 2 * n + 1; i++) if(i != n + 1) ans *= i;

    cout << ans << endl;
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
```

