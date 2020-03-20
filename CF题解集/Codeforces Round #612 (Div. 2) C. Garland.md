# Codeforces Round #612 (Div. 2) C. Garland

Vadim loves decorating the Christmas tree, so he got a beautiful garland as a present. It consists of n light bulbs in a single row. Each bulb has a number from 1 to n (in arbitrary order), such that all the numbers are distinct. While Vadim was solving problems, his home Carp removed some light bulbs from the garland. Now Vadim wants to put them back on.

![img](https://espresso.codeforces.com/c87ff8b17badad0f05d83d783c8343a0a00725a6.png)

Vadim wants to put all bulb back on the garland. Vadim defines *complexity* of a garland to be the number of pairs of adjacent bulbs with numbers with different parity (remainder of the division by $2$). For example, the complexity of 1  4  2  3  5 is 2  and the complexity of ​1 3 5 7 6 4 2​ is $1$.

No one likes complexity, so Vadim wants to minimize the number of such pairs. Find the way to put all bulbs back on the garland, such that the complexity is as small as possible.

Input

The first line contains a single integer $n (1≤n≤100)$ — the number of light bulbs on the garland.

The second line contains n integers $p1, p2, …, pn (0≤pi≤n)$ — the number on the $ i-th $ bulb, or $0$ if it was removed.

Output

Output a single number — the minimum *complexity* of the garland.

Examples

input

```
5
0 5 0 2 3
```

output

```
2
```

input

```
7
1 0 0 5 0 0 2
```

output

```
1
```

Note

In the first example, one should place light bulbs as 1 5 4 2 3. In that case, the complexity would be equal to 2, because only (5,4)and (2,3) are the pairs of adjacent bulbs that have different parity.

In the second case, one of the correct answers is 1 7 3 5 6 4 2.



思路：动态规划

一维：长度，

二维：剩余偶数个数

三维：当前数奇偶性

界限：

* 当存在偶数且第一个数为0或偶数：$dp[1][n/2-1][0] = 0$ 
* 当第一个数为 00 或奇数：$dp[1][n/2][1] = 0$ 

状态转移：

* 当前填偶数：$dp[i][j-1][0] = min(dp[i][j-1][0], dp[i-1][j][k] + (k==1))$ 
* 当前填奇数：$dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][k] + (k==0))$ 

AC: 

```cpp
#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, a[maxn], dp[maxn][maxn][2];
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    if(n > 1 && (a[1] == 0 || a[1] % 2 == 0))
        dp[1][n / 2 - 1][0] = 0;
    if(a[1] % 2 == 1 || a[1] == 0)
        dp[1][n / 2][1] = 0;
    for (int i = 2; i <= n; i++){
        for (int j = 0; j <= n / 2; j++){
            for (int k = 0; k < 2; k++){
                if(j > 0 && (a[i] == 0 || a[i]%2 == 0))
                    dp[i][j - 1][0] = min(dp[i][j - 1][0], dp[i - 1][j][k] + (k == 1));
                if(i+j-1 < n && (a[i] == 0 || a[i] % 2 == 1))
                    dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][k] + (k == 0));
            }
        }
    }
    cout << min(dp[n][0][0], dp[n][0][1]) << endl;
    return 0;
}
```

