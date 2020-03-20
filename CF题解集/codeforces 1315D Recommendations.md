# codeforces 1315D Recommendations

### 题意：

​	每个点两个属性，$a[ i ],t[ i ]$（给该点$a[ i ] +1$的消耗），现在要求$a_i$各不相同，问你最小花费

### 题解：

​	按照时间从大到小，序号从小到大，用并查集维护祖先，用来表示该点最终需要加到多大的值，并通过祖先计算自身需要进行几次操作，答案就加上几次相应的时间。

​    一开始默认$fa[i]$都为$0$，意思是$find(i)$都为自己本身，因为每个数字最多出现一次，那么当我们遍历到一个数字$x$的时候，就说明这个$x$之后不能再出现了，再次出现的$x$必须变成$x+1$，同理出现了$x+1$之后就必须变成$x+2$，这就要$unite(x,x+1)$，(不能$unite(x+1,x)$，因为祖先肯定比$x$大)这一步操作结束之后，相当于是处理出了这个数字在最终需要变为的数字。两者相减即为操作次数，乘上时间就是对答案的贡献，由于处理是从前往后的，所以对于同一个$x$,时间小的肯定放在后面(贪心思想)。

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll> 
const int maxn = 2e5 + 10;
ll a[maxn], t[maxn];
map<ll, ll> fa;
pll q[maxn];
bool cmp(pll &a, pll &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

ll find(ll x){
    return fa[x] == 0 ? x : fa[x] = find(fa[x]);
}
void unit(ll x, ll y){
    x = find(x), y = find(y);
    if(x != y)
        fa[x] = y;
}
int main(){
    int n;

    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> a[i];
    }
    for (int i = 0; i<n; i++){
        cin >> t[i];
        q[i].first = a[i];
        q[i].second = t[i];
    }
    sort(q, q + n, cmp);
    /*for (int i = 0; i < n; i++){
        cout << q[i].first << " " << q[i].second << endl;
    }*/
    ll ans = 0;
    for (int i = 0; i < n; i++){
        ll x = find(q[i].first);
        ans += (x - q[i].first) * q[i].second;
        unit(x, x + 1);
    }
    cout << ans << endl;
    return 0;
}
```

