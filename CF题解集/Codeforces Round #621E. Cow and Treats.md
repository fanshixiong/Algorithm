## [Codeforces Round #621](https://codeforces.com/contest/1307)[E. Cow and Treats](https://codeforces.com/contest/1307/problem/E)



​	 	**题意**：有n个草排成一列，每个草有一个甜味值；有m头牛，每头牛有一个自己喜欢的甜味值f和饥饿程度h，意思是这头牛只吃这个甜味值的草，并且吃h个就会饱；你需要在这列草的左右确定两个牛的集合，你可以决定牛的前后顺序以及吃草的方向，牛吃草的原则如下： 每头牛确定了吃草方向后就只能向那个方向走； 每头牛只吃自己喜欢的甜味值的草，不是这个甜味值直接跳过； 每头牛在吃了h个草之后会就地睡在这个格子上； 如果一头牛遇到了睡着的牛或者走到尽头还是没有吃够它就会不高兴；  农夫想要选择尽可能多的牛使得他们都高兴，问你最大数量以及方案数（左右两个集合内元素不同就视为不同的方案）；  

  	  **思路**：我们可以很显然地发现一个性质，就是一个集合内不可能出现两个及以上的甜味值相同的牛。由于这个性质，我们可以知道每头牛最后睡的格子都是互不相同的，那么如果一个可行的集合确定了，必然有一个可行的顺序使得每头牛都可以开心，我们只需要确定这个集合有多少种即可（实际上题目也是这么要求的）； 我们可以枚举向右走的第一头牛的编号（当然也可以没有牛向右走），假设这时候这头牛到达的位置为p，那么我们就将区间分为了$[1,p-1]$和$[p+1,n]$这两段，对于每一段可以单独思考； 对于段内的甜味值f，我们可以统计出这段内有多少个这个味道的草，记为$c$，那么我们就需要知道有多少头牛可以放在这一段的开头，显然数量就是甜味值为f并且饥饿值小于等于$c$的牛的数量。于是我们有了两个值$x$和$y$，分别表示对于当前甜味值f，可以放在左右的牛的数量，方便起见，我们令$x<=y$（后面会说为什么）。计算方案数和睡觉的牛的数量时有三种case，分别是：

* 1、$x=0，y!=0$，此时数量加上1，方案数乘$y$； 

* 2、$x=1，y=1$，此时数量加1，方案数乘2；（因为一共只有一头牛满足条件，显然只有放左边或者放右边两种情况） 

* 3、其他所有情况，此时数量加2，方案数乘$x*(y-1)$；（这里要求$x<=y$，因为一头牛如果满足了x那边就必然满足y那一边，所以在乘了x之后y就会有一头牛被用掉）。

  

  又因为每段内的不同颜色是互不干扰的，所以方案数直接累乘即可；  需要特判的有，在判断颜色时如果这个颜色和一开始枚举的第一头牛的颜色相同那么x直接就等于0，如果右边这个颜色的草的数量大于等于左边那y也要减去1（因为本来我枚举的这头牛是可以出现在y里的，但是现在确定了位置就不可以）

```cpp
#include<bits/stdc++.h>
using namespace std;#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e4 + 10;
const int mod = 1e9 + 7;
int m, n, mx = 0;
int l[maxn], r[maxn], a[maxn];
vector<int> v[maxn];
ll ans = 0;
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++){
        int h, f;
        cin >> f >> h;
        v[f].push_back(h);
    }
    for (int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end());
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            l[j] = r[j] = 0;
        }
        for (int j = 1; j <= i; j++){
            l[a[j]]++;
        }
        for (int j = i + 1; j <= n; j++){
            r[a[j]]++;
        }
        int ok = i == 0, num = i != 0;
        ll s = 1;
        for(auto x : v[a[i]]){
            if(x == l[a[i]]){
                ok = 1; break;
            }
        }

        if(!ok)  continue;

        for (int j = 1; j <= n; j++){
            int x = 0, y = 0, sz = v[j].size();
            while(x < sz && v[j][x] <= l[j]) x++;
            while(y < sz && v[j][y] <= r[j]) y++;
            if(j == a[i]){  
                x = 0;  y -= (r[j] >= l[j]);
            }
            if(x + y == 0) continue;
            if(x > y) swap(x, y);
            if(!x){
                num ++; s = s * y % mod;
            }
            else if(y == 1){
                num ++; s = s * 2 % mod;
            }
            else{
                num += 2; s = s * x * (y - 1) % mod;
            }
        }
        
        if(num > mx){
            mx = num; ans = 0;
        }
        if(num == mx){
            ans = (ans + s) % mod;
        }
    }

    cout << mx << " " << ans << endl;
    return 0;
}
```