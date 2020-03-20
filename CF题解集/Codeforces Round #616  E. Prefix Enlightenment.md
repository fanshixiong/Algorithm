# [Codeforces Round #616](https://codeforces.com/contest/1291)  E. Prefix Enlightenment

There are n lamps on a line, numbered from 1 to n. Each one has an initial state off (0) or on (1).

You're given k subsets $A_1,…,A_k of {1,2,…,n}$, such that the intersection of any three subsets is empty. In other words, for all $1≤i1<i2<i3≤k, Ai1∩Ai2∩Ai3=∅$.

In one operation, you can choose one of these k subsets and switch the state of all lamps in it. It is guaranteed that, with the given subsets, it's possible to make all lamps be simultaneously on using this type of operation.

Let mi be the minimum number of operations you have to do in order to make the i first lamps be simultaneously on. Note that there is no condition upon the state of other lamps (between i+1 and n), they can be either off or $O(n)$.

You have to compute mi for all $1≤i≤n$.



#### Input

The first line contains two integers n and k $(1≤n,k≤3⋅105)$.

The second line contains a binary string of length n, representing the initial state of each lamp (the lamp i is off if $s_i=0$, on if $s_i=1$).

The description of each one of the k subsets follows, in the following format:

The first line of the description contains a single integer$ c (1≤c≤n)$ — the number of elements in the subset.

The second line of the description contains c distinct integers$ x_1,…,x_c (1≤x_i≤n) $— the elements of the subset.

It is guaranteed that:

The intersection of any three subsets is empty;
It's possible to make all lamps be simultaneously on using some operations.



#### Output

You must output n lines. The i-th line should contain a single integer mi — the minimum number of operations required to make the lamps 1 to i be simultaneously on.



#### Examples

input

```
7 3
0011100
3
1 4 6
3
3 4 7
2
2 3
```

output

```
1
2
3
3
3
3
3
```

input

```
8 6
00110011
3
1 3 8
5
1 2 5 6 7
2
6 8
2
3 5
2
4 7
1
2
```

output

```
1
1
1
1
1
1
4
4
```

input

```
5 3
00011
3
1 2 3
1
4
3
3 4 5
```

output

```
1
1
1
1
1
```

input

```
19 5
1001001001100000110
2
2 3
2
5 6
2
8 9
5
12 13 14 15 16
1
19
```

output

```
0
1
1
1
2
2
2
3
3
3
3
4
4
4
4
4
4
4
5


```



#### Note

In the first example:

For i=1, we can just apply one operation on A1, the final states will be 1010110;
For i=2, we can apply operations on A1 and A3, the final states will be 1100110;
For i≥3, we can apply operations on A1, A2 and A3, the final states will be 1111111.
In the second example:

For i≤6, we can just apply one operation on A2, the final states will be 11111101;
For i≥7, we can apply operations on A1,A3,A4,A6, the final states will be 11111111.



#### 题意

有n个灯泡，初始灯泡可能是开着的，也可能是关着的。 k个开关集合，每个集合控制着c个开关。

现在对应每个前缀1~i，问你最少需要操作多少个集合呢？

有两个关键条件：

* 任意三个开关集合的交集为空
* 保证有解。



#### 题解

任意三个开关集合的交集为空的意思就是，一个灯泡最多由两个开关集合控制。

把每个开关集合都拆分成两个状态，一个叫做使用，一个叫做不使用。

如果第i个灯泡由第x和第y个开关集合控制，如果i灯泡初始是关着的，那么我缩点x开和y关，缩点x关和y开；同理

如果i灯泡初始是开着的，我们缩点x关和y关，x开和y开。然后我选择最小的连体块大小即可。

特殊处理只由1个开关集合控制的灯泡情况。

#### 代码

```cpp
#include<bits/stdc++.h>
using namespace std;
const int maxn = 6e5+10;
int n, k;
string s;
int l[maxn][2], root[maxn], cnt[maxn];
int getroot(int x){
    if(x == root[x])
        return x;
    return root[x] = getroot(root[x]);
}
int calc(int x){
    int y = x <= k ? x + k : x - k;
    x = getroot(x);
    y = getroot(y);
    if(x == 0 || y == 0)
        return cnt[x + y];
    return min(cnt[x], cnt[y]);
}
void merge(int x, int y){
    x = getroot(x);
    y = getroot(y);
    if( y == 0){
        swap(x, y);
    }
    root[y] = x;
    if(x != 0)
        cnt[x] += cnt[y];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    cin >> s;
    for (int i = 1; i <= k; i++){
        int c;
        cin >> c;
        for (int j = 0; j<c; j++){
            int x;
            cin >> x;
            if(l[x][0] == 0)
                l[x][0] = i;
            else
                l[x][1] = i;
        }
        root[i] = i;
        root[i + k] = i + k;
        cnt[i + k] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if(l[i][1] == 0){
            int x = l[i][0];
            if(x){
                ans -= calc(x);
                if(s[i-1]=='1'){
                    root[getroot(x + k)] = 0;
                }
                else{
                    root[getroot(x)] = 0;
                }
                ans += calc(x);
            }
        }
        else{
            int x = l[i][0], y = l[i][1];
            if(s[i-1] == '1'){
                if(getroot(x) != getroot(y)){
                    ans -= calc(x);
                    ans -= calc(y);
                    merge(x, y);
                    merge(x + k, y + k);
                    ans += calc(x);
                }
            }
            else{
                if(getroot(x+k) != getroot(y)){
                    ans -= calc(x);
                    ans -= calc(y);
                    merge(x + k, y);
                    merge(x, y + k);
                    ans += calc(x);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
```