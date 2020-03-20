# Codeforces Round #626 (Div. 2) E. Instant Noodles（二分图，最大公因数）

### 题意：

给你一个二分图，求左侧端点的所有可能子集中的点相连的右侧端点的权值的和的最大公因数。

### 题解：

若所有右侧端点均不在同一左侧子集中，则求所有权值的最大公因数即可 。

否则，将在相同左侧子集中的右侧权值合并，求合并权值与其余权值的最大公因数。

### 证明 ：

$gcd(a,a+b)=gcd(a,b)，gcd(a,b,c)=gcd(a,gcd(b,c))。$





完全不懂啊。

啥时候才能懂。。。



```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<vector<int>, ll>> v;

bool cmp(pair<vector<int>, ll> &a, pair<vector<int>, ll> &b){
    if(a.first.size() != b.first.size())
        return a.first.size() < b.first.size();
    return a.first < b.first;
}
void solve(){
    int n, m;
    cin >> n >> m;

    v.clear(); v.resize(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].second;
    }
    for (int i = 0; i<m; i++){
        int x, y;
        cin >> x >> y;
        --x; --y;
        v[y].first.push_back(x);
    }

    for (int i = 0; i < n; i++){
        sort(v[i].first.begin(), v[i].first.end());
    }
    sort(v.begin(), v.end(), cmp);

    ll ans = 0;

    int i = 0;
    while(v[i].first.empty()) i++;
    while(i < n){
        int j = i;
        ll sum = 0;
        while(j < n && (v[i].first == v[j].first)){
            sum += v[j].second;
            ++j;
        }
        ans = __gcd(ans, sum);
        i = j;
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

 