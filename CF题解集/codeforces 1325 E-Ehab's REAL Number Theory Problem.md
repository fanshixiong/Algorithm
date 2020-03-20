## codeforces 1325 E-Ehab's REAL Number Theory Problem 

####  原题：

#### 	[E. Ehab's REAL Number Theory Problem](https://www.luogu.com.cn/problem/CF1325E)

#### 题意：

	1. Every element in this array has at most 7 divisors.
 	2. 从中挑出几个数，使得他们的乘积为完全平方数，问你最少要挑几个？

#### 题解：

> Every element in this array has at most 7 divisors.

翻译一下就变成了：

> 该数组中每个元素的质因子不超过2个。                           ①

这个条件肯定有用。

接着思考一下：如果我们将一个数质因数分解，并将每一个因式的指数都模2，不会影响最终结果。或者换句话说，如果一个数能够被一个完全平方数整除，我们就把这个数除以该完全平方数。

举个例子：现在我们有 $12,75,10 $三个数。

质因数分解：

- $12=2^2×3$
- $75=3 ×5^2$
- $10=2×5$

最后的答案应该是$2$，因为我们可以选择$12$和$75$.而我们之所以这么选择是因为 $12 * 75 = 2^2 * 3^2 * 5^2=2^2×3^2×5^2$ ，这是一个完全平方数。

但我们如果一开始把指数模2：

- $12=2^2×3→3=3$
- $75=3 \times 5^2 \rightarrow 3=3$
- $10=2 \times 5 \rightarrow 2 \times 5=10$

最终结果不受影响，我们还是会选择前两个数。

所以我们首先把所有数质因数分解并按如上所述的方法处理。接下来有一句话就要派上用场了：

> 该数组中每个元素的质因子不超过2个。

于是最终数组的每个元素都可以表示成一下三种方式的一种：

1. $1$
2. 一个质数 $p$
3. 两个质数 $p,q$ 的乘积 $p \times q$

如果有任何一个元素为1，直接输出1就结束了。

接下来怎么办？

我的一个同学说过一句话：

> 遇事不决建个图。

我们把出现的所有质因子和数1表示成点，把数组的元素表示成一条边，如果这个元素是上面的第3种情况，我们就在节点 $p$ 和节点 $q$  之间建边。如果是第2种情况，我们就在节点 $p$和节点 $1$ 之间建边。所有的边是无向的且边权为1.

我们最终的答案其实就是这个图中的最小环。

举两个具体的例子帮助大家理解：

###### Example 1

第一个例子是CF原题的第3个样例：

###### Input

```
3
6 15 10
```

###### Output

```
3
```

最后我们建出来的图如下：

![Example 1](https://cdn.luogu.com.cn/upload/image_hosting/k51sq5wq.png)

所有的边权均为1，这里的边旁边的信息指的是它所对应的原数组中的元素（下标从1开始）。

图中的最小环长度为3，所以答案是3.

###### Example 2

第二个例子是CF原题的第4个样例：

###### Input

```
4
2 3 5 7
```

###### Output

```
-1
```

建出来的图长这样：

![Example 2](https://cdn.luogu.com.cn/upload/image_hosting/uo8p1okw.png)

图中根本就没有最小环，所以答案为-1.

But why?

因为我们的每一条边的意义就是把这条边两端的节点所对应的数相乘，而如果我们走一个环，这个环上每个节点都乘了两次，最终的乘积肯定是个完全平方数。而我们的每条边对应数组的1个元素，边权为1，最小环就代表选的数最少。

用**bfs**求最小环就可以了。 ②

可是时间复杂度$ O(n^2)$ ，怎么优化？

我们在所有的 $a_i$里找到 $max\ a_i$ ，令 $m=\sqrt{max\ a_i}$  ，则我们在**bfs**求最小环时的起点都不能超过 *m* ，所走的边的两端的乘积就会大于 $max\ a_i $。     ③

优化完成，可以过了。

回顾、总结一下思路：

- 首先处理数组的每个元素，简化成3种形式。
- 然后建图，求最小环。
- 最后进行时间复杂度上的优化，完成该题。

时间复杂度：$\mathcal{O}(nm)$

AC代码如下：

```cpp
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int maxa = 1000010;
int n, a[maxn], maxx;

vector<int> prime;
bool isp[maxa];
int pr_tot;

bool changed[maxa]; 
vector<int> p[maxa]; 

int h[maxa], en;
struct Edge
{
    int u;
    int v;
    int next;
};
Edge e[2 * maxn];

int ans;
int dis[maxa];
//线性素数筛法
void find_prime(int x)
{
    fill(isp + 2, isp + x + 1, true);
    for(int i = 2; i <= x; i++)
    {
        if(isp[i])
        {
            prime.push_back(i);
            pr_tot++;
        }
        for(int j = 0; j < pr_tot && i * prime[j] <= x; j++)
        {
            isp[i * prime[j]] = false;
            if(i % prime[j] == 0)
                break;
        }
    }
    return;
}
//分解质因数并将该数简化
void divide(int x)
{
    int var = x;
    for(int i = 2; i * i <= var; i++)
        if(x % i == 0)
        {
            int index = 0;
            while(x % i == 0)
            {
                x /= i;
                index++;
            }
            if(index % 2 == 1)
                p[var].push_back(i);
        }
    if(isp[x])
        p[var].push_back(x);
    return;
}
//建边
void addedge(int u, int v)
{
    en++;
    e[en].u = u;
    e[en].v = v;
    e[en].next = h[u];
    h[u] = en;
    return;
}
//bfs求最小环
void bfs()
{
    ans = INT_MAX;
    prime.insert(prime.begin(), 1);
    for(int i = 0; i <= pr_tot; i++)
    {
        if((long long)prime[i] * prime[i] > maxx)
            break;
        queue<pair<int, int> > q;
        fill(dis + 1, dis + maxx + 1, INT_MAX);
        q.push(make_pair(prime[i], 0));
        dis[prime[i]] = 0;
        while(!q.empty())
        {
            pair<int,int> tmp = q.front();
            q.pop();
            int u = tmp.first, fa = tmp.second;
            for(int j = h[u]; j != 0; j = e[j].next)
            {
                int v = e[j].v;
                if(v == fa)
                    continue;
                if(dis[v] == INT_MAX && v != prime[i])
                {
                    dis[v] = dis[u] + 1;
                    q.push(make_pair(v, u));
                }
                else
                    ans = min(ans, dis[u] + dis[v] + 1);    
            }
        }
    }
    if(ans == INT_MAX)
        ans = -1;
    return;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    find_prime(maxx);
    for(int i = 1; i <= n; i++)
    {
        if(!changed[a[i]])
            divide(a[i]);
        changed[a[i]] = true;
    }
    for(int i = 1; i <= n; i++)
    {
        if(p[a[i]].empty())
        {
            cout << 1 << endl;
            return 0;
        }
        if(p[a[i]].size() == 1)
            p[a[i]].push_back(1);
        addedge(p[a[i]][0], p[a[i]][1]);
        addedge(p[a[i]][1], p[a[i]][0]);
    }
    bfs();
    cout << ans << endl;
    return 0;
}
```





----

注： 本文搬运[Andrewzdm ](https://www.luogu.com.cn/blog/0408Dodgemin/cf1325e-ti-xie)的博客，思路很是清楚。

  ①： 为什么是最多2个质因数的乘积，若为3个或者三个以上的质因数，比如：$3\times5\times7$,  它的因数有：$1、3、5、7、3\times7、5\times7、3\times5、3\times5\times7$，是8个因数，所以最多有两个质因数。 

  ②：**bfs求最小环**：存储上一个节点和当前节点，遇到已经bfs过的节点直接更新答案，否则往队列里面扔。

  ③：所有大于 *m* 的质数之间不可能连边，否则就超过了 $\max a_i$。所以枚举起点的时候只需要枚举 $1\sim m$。