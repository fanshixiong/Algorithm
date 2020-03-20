## [Codeforces Round #622](https://codeforces.com/contest/1313)     [C2 - Skyscrapers](https://codeforces.com/contest/1313/problem/C2)(单调栈)

#### 题意：

给一个整数$n$以及一个数组$m$。 构建一个数组$a$满足：$1≤a_i≤m_i$，且不存在这样的情况$j<i<k，a_j>a_i<a_k$

求数组的和最大的方案。

#### 思路：

我们知道要满足数组的条件，数组必须是一个单峰数组。即我们只需要找到那个数组的峰值的下标即可。

用单调栈维护两个数组：

$l[i]$代表从$1$到$i$ 单调不减时最大的前缀和。

$r[i]$代表从$i$到$n$ 单调不升时最大的后缀和。

那么我们找到$l[i] + r[i] - h[i]$的最大值下标就是目标数组的峰值下标，然后输出答案即可。

视频讲解可以参考：[WNJXYK](https://www.bilibili.com/video/av91310263?p=4) 和 [卿学姐](https://www.bilibili.com/video/av91242850?p=3)

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 5e5+10;
ll n, l[maxn], r[maxn], h[maxn];
pair<int, int> s[maxn];
void solve(ll ans[]){
    int top = 0;
    ll cur = 0;
    s[top] = make_pair(0, 0);

    for (int i = 1; i <= n; i++){
        while(top && s[top].first > h[i]){
            cur -= (1ll * s[top].first * (s[top].second - s[top - 1].second));
            top--;
        }
        cur += (1ll * h[i] * (i - s[top].second));
        s[++top] = make_pair(h[i], i);
        ans[i] = cur;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> h[i];
    }
    solve(l);
    reverse(h + 1, h + 1 + n);
    solve(r);
    reverse(h + 1, h + 1 + n);
    reverse(r + 1, r + 1 + n);
    
    ll ans = r[1], pos = 1;
    for (int i = 1; i <= n; i++){
        ll t = l[i] + r[i] - h[i];
        if(ans < t){
            ans = t;
            pos = i;
        }
    }
    
    ll res[n + 1]; res[pos] = h[pos];
    for (int i = pos - 1; i >= 1; i--){
        res[i] = min(res[i + 1], h[i]);
    }
    for (int i = pos + 1; i <= n; i++){
        res[i] = min(res[i - 1], h[i]);
    }

    for (int i = 1; i <= n; i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
```

