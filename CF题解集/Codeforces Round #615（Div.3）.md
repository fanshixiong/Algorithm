## Codeforces Round #615（Div.3）

### A. Collecting Coins

注意\(n\)可能不够用的情况。

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;
int main(){
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    while(n--){
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        int ma = max(a, max(b, c));
        int cnt = abs(ma - a) + abs(ma - b) + abs(ma - c);
        int remain = n - cnt;
        if(remain >= 0 && remain % 3 == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
```

### B. Collecting Packages

直接模拟这个过程就好了，注意字典序最小的方案。

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end());
    string ans;
    pair<int, int> cur = make_pair(0, 0);
    for (int i = 0; i < n; i++){
        int r = v[i].first - cur.first;
        int u = v[i].second - cur.second;
        if(r < 0 || u < 0){
            cout << "NO" << endl;
            return;
        }
        ans += string(r, 'R');
        ans += string(u, 'U');
        cur = v[i];
    }
    cout << "YES" << endl << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```

### C. Product of Three Numbers

枚举因数，看看能不能成。

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;
void solve(){
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 2; i <= sqrt(n); i++){
        if(n%i == 0){
            v.push_back(i);
            n /= i;
        }
        if(v.size() == 2){
            if(n>i){
                cout << "YES" << endl;
                cout << v[0] << " " << v[1] << " " << n << endl;
                return;
            }
            else{
                cout << "NO" << endl;
                return;
            }
        }
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

### D. MEX maximizing

根据贪心的思路我们可以发现答案一定是递增的，所以我们就直接把所有的点都减到不能减为止，然后答案可以变大的时候用他们来做贡献。

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;
int main(){
    ios_base::sync_with_stdio(0);
    int q, x;
    cin >> q >> x;
    unordered_map<int, int> mp;
    int ans = 0;
    while(q--){
        int num;
        cin >> num;
        mp[num % x]++;
        while(mp[ans])
            ans++;
        while(mp[ans%x] > 1){
            mp[ans%x]--;
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
```

### E. Obtain a Permutation

题意也就是用最少的操作次数使得矩阵每个元素\(a(i,j)=(i-1)*m+j\)。

分析一下的话可以发现，每一列其实是独立的，所以最终答案一定是每一列的答案相加。

考虑第\(j\)列，最终第\(j\)列的元素就为\(j,j+m,j+2m,...,j+(n-1)*m\)。

对于给出的第\(j\)列数字，可以枚举谁作为最高位，从而来计算答案。

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e4 + 10;
//int a[maxn][maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector< vector<int> > a(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j<m; j++){
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    ll ans = 0;
    for (int j = 0; j < m; j++){
        vector<int> cnt(n);
        for (int i = 0; i < n; i ++){
            if(a[i][j] % m == j){
                int pos = a[i][j] / m;
                if(pos < n){
                    cnt[(i + n - pos) % n]++;
                }
                //else
                //    cnt[(pos - n) % n]++;
            }
        }
        int tmp = n - cnt[0];
        
        for (int i = 1; i < n; i++){
            tmp = min(tmp, i + n - cnt[i]);
        }
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}
```

### F. Three Paths on a Tree

首先可以确定的是，其中的两个点一定在直径的两个端点上。

第三个点要怎么确定呢？

设$(len(a,b))$表示$(a)$到$(b)$的距离，那么答案就是$(\frac{len(a,b)+len(b,c)+len(a,c)}{2})$。

所以我们找$(len(a,c)+len(b,c))$最大就行了。

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5 + 10;

vector<int> G[maxn];
int vis[maxn], sum[maxn];

int bfs(int u){
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(u);
    int t;
    while(q.size()){
        t = q.front();
        q.pop();
        for (int i = 0; i < G[t].size(); i++){
            int v = G[t][i];
            if(!vis[v] && v != u){
                q.push(v);
                vis[v] = vis[t] + 1;
            }
        }
    }
    return t;
}
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1, x, y; i<n; i++){
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int u = bfs(1), v = bfs(u), ans = 0, w;
    //此时的vis数组中存着每个点离u的距离
    
    
    //sum数组中存着len(u,v)+len(u,i)
    for (int i = 1; i <= n; i++)
        sum[i] = vis[v] + vis[i];
    bfs(v);//vis数组中存着每个点离v的距离
    
    for (int i = 1; i <= n; i++){
    	//sum中存着len(u,v)+len(u,i)+len(v,i)
    	sum[i] += vis[i];
        if(i != u && i != v && sum[i] > ans)
            ans = sum[i], w = i;
    }
    cout << ans/2 << endl << u << " " << v << " " << w << endl;
    return 0;
}
```





