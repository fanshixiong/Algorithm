# [Codeforces Round #617 ](https://codeforces.com/contest/1296)  E F题解

#### [E2 - String Coloring](https://codeforces.com/contest/1296/problem/E2)

**Dilworth定理** :  偏序集分解定理，是关于偏序集的极大极小的定理，该定理断言：对于任意有限偏序集，其最大反链中元素的数目必等于最小链划分中链的数目。

本题就是单调不减序列的个数，即为单调减序列的最大长度。

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5+10;
int a[30], ans[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = n; i >= 1; i--){
        ans[i] = lower_bound(a + 1, a + 1 + cnt, s[i - 1] - 'a') - a; //在a数组里找1-cnt中的第一个大于等于s[i]的位置
        cnt = max(cnt, ans[i]);
        a[ans[i]] = s[i - 1] - 'a';
    }
    cout << cnt << endl;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    
    return 0;
}
```

