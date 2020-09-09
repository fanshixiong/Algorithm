# Codeforces Round #668 (Div. 2) D - Tree Tag



![](https://img-blog.csdnimg.cn/20200908091846842.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MzkxMTk0NQ==,size_16,color_FFFFFF,t_70#pic_center)

## 题意:

*   $a$先手，并且$a$最多走$da$步，$b$最多走$db$步。
*   $a$和$b$都在树上，$a$要追到$b$的话$Alice$胜利，否则$Bob$胜利。

## 题解:

$a$胜利有两种情况: 

1.  初始$a$、$b$距离小于等于$da$
2.  $da$大于等于树直径一半
3.  $da * 2 + 1 > db$ *表a把b追到死胡同的时候，b需要反向跑，不存在A只差一步追上B的时候，B可以反向再跑一段很长的距离，使得A一步追不上B。

## 代码:

注意：*$dfs$用fa代替$vis[]。$*

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;
vector<int> G[maxn];
int dist; //a b距离
int n, a, b, da, db;
int max_len, p;
void dfs(int u, int fa, int d){
    if(d > max_len){
        max_len = d;
        p = u;
    }
    if(u == b && !dist) dist = d;  

    for(auto v:G[u]){
        if(v == fa) continue;
        dfs(v, u, d+1);
    }
}
int maxLength(){
    max_len = -1;
    p = 0;
    dfs(a, -1, 0);
    dfs(p, -1, 0);
    return max_len;
}
void solve(){
    cin >> n >> a >> b >> da >> db;
    for (int i = 0; i <= n; i++) G[i].clear();

    for (int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dist = 0;
    int len = maxLength();
    if (da >= (len + 1) / 2 || da >= dist || da * 2 + 1 > db /*代表a把b追到死胡同的时候，b需要反向跑，
    不存在A只差一步追上B的时候，B可以反向再跑一段很长的距离，使得A一步追不上B。*/) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}
int main(){
    IOS; int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```

