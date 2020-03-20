# Educational Codeforces Round 78  C - Berry Jam



### 题目



Karlsson has recently discovered a huge stock of berry jam jars in the basement of the house. More specifically, there were 2n jars of strawberry and blueberry jam.

All the 2n jars are arranged in a row. The stairs to the basement are exactly in the middle of that row. So when Karlsson enters the basement, he sees exactly n jars to his left and n jars to his right.

For example, the basement might look like this:
![img](https://uploadfiles.nowcoder.com/images/20191223/517318077_1577097924303_8F079454660B77C941FD8C211F494797)
Being the starightforward man he is, he immediately starts eating the jam. In one minute he chooses to empty either the first non-empty jar to his left or the first non-empty jar to his right.

Finally, Karlsson decided that at the end the amount of full strawberry and blueberry jam jars should become the same.

For example, this might be the result:

He has eaten 1 jar to his left and![img](https://uploadfiles.nowcoder.com/images/20191223/517318077_1577097924431_8F079454660B77C941FD8C211F494797) then 5 jars to his right. There remained exactly 3 full jars of both strawberry and blueberry jam.
Jars are numbered from 1 to 2n from left to right, so Karlsson initially stands between jars n and n+1.

What is the minimum number of jars Karlsson is required to empty so that an equal number of full strawberry and blueberry jam jars is left?

Your program should answer t independent test cases.

**Input**
The first line contains one integer t (1≤t≤1000) — the number of test cases.

The first line of each test case contains a single integer n (1≤n≤105).

The second line of each test case contains 2n integers a1,a2,…,a2n (1≤ai≤2) — ai=1 means that the i-th jar from the left is a strawberry jam jar and ai=2 means that it is a blueberry jam jar.

It is guaranteed that the sum of n over all test cases does not exceed 105.

**Output**
For each test case print the answer to it — the minimum number of jars Karlsson is required to empty so that an equal number of full strawberry and blueberry jam jars is left.

Example
**input**

```
4
6
1 1 1 2 2 1 2 1 2 1 1 2
2
1 2 1 2
3
1 1 1 1 1 1
2
2 1 1 1
```

**output**

```
6
0
6
2
```

**Note**
The picture from the statement describes the first test case.

In the second test case the number of strawberry and blueberry jam jars is already equal.

In the third test case Karlsson is required to eat all 6 jars so that there remain 0 jars of both jams.

In the fourth test case Karlsson can empty either the second and the third jars or the third and the fourth one. The both scenarios will leave 1 jar of both jams.





### 题意

  可以从中间往左连续吃几罐，从中间往右连续吃几罐，最少一共吃多少可以使剩下的红蓝罐数目相等

---





### 思路



   这个题需要换成1-1序列之后，求出一个**前缀和与后缀和相加等于0**的位置，后缀和可以由前缀和相减得到，所以我们只计算一个前缀和；枚举右边吃了多少，**对于每一个后缀和查找是否有和他互为相反数的前缀和**（用一个**map来记录前一半数的前缀和等于某个值时出现的位置**，后缀和用前缀和相减就可以了。然后从中间向后遍历，遍历的值减去最后前缀和的值，然后看看map里面是否有这个值，如果有计算一下需要吃几个，每次取最小的结果就可以了），最后就是注意边界问题，因为可能往左往右一个不吃；

```
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int sum[maxn*2];
void solve(){
    int n;
    cin >> n;
    map<int, int> pos;
    pos[0] = 0; //往左全部吃完
    memset(sum, 0, sizeof(sum));
    for(int i=1; i<=n*2; i++){
        int a;
        cin >> a;
        if(a == 2)
            a = -1;     
        sum[i] = sum[i-1] + a;
        if(i <= n)
            pos[sum[i]] = i;
    }
    int ans = n*2;
    for(int i=n; i<=n*2; i++){
        auto it = pos.find(sum[i]-sum[2*n]);
        if(it != pos.end()){
            ans = min(i-it->second, ans);
        }
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





​    我们用sum[i]-sum[n*2],是因为前缀合计算的是 1比2多了几个，我们这样减了一下刚好是2比1多了几个。如果前面刚好有1比2多的数量等于后面从i这个位置2比1多的数量，那么把中间的这部分吃了就刚好。我们这样顺序遍历下最后取最小值就可以了。