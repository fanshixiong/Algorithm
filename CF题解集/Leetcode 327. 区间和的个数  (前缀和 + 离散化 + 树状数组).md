## [Leetcode 327. 区间和的个数](https://leetcode-cn.com/problems/count-of-range-sum/)  (前缀和 + 离散化 + 树状数组)



### 题目

![image-20201107214122541](F:\c++\Game\CF题解集\Leetcode 327. 区间和的个数  (前缀和 + 离散化 + 树状数组).assets\image-20201107214122541.png)

### 题意

 有多少个连续的子数组，其和在$[lower, upper]$之间

### 题解

可以想到的做法：用前缀和在$O(1)$查询$[i, j]$的和，枚举所有的二元组$[i, j]$, 满足条件就加上。

可以优化为：$Pre$为前缀和数组， 从小到大枚举 $j$， 由于$\textit{lower} \leq Pre[j] - Pre[i-1] \leq \textit{upper}$ ，可以得到 $P[i-1]$ 满足$Pre[j] - \textit{upper} \leq Pre[i-1] \leq Pre[j] - \textit{lower}$ ，通过枚举$j$，可以将$[Pre[j] - \textit{upper}, Pre[j] - \textit{lower}]$ 看做$[L, R]$, 之后查询所有$[L, R]$内的个数即为答案。



*   前缀和 

​        使用前缀和算出子数组$[i, j]$的和$Pre[j]-Pre[i]$。

*   离散化

   由于数据范围较大，因此可以通过离散化降低数据。我们可以将$Pre[j] - \textit{upper}, Pre[j] - \textit{lower}, Pre[j]$ 一起排序后进行离散化。

*   树状数组 / 线段树 / 平衡树

   这些数据结构都满足在$O(logn)$ 的时间复杂度查询$[L, R]$内的和。



### 代码

```cpp
#define ll long long
class Solution {
public:
    vector<int> tree;
    int n;
    int lowbits(int x){
        return x & (-x);    
    }
    void update(int x){
        while(x <= n){
            tree[x] += 1;
            x += lowbits(x);
        }
    }
    int query(int x){
        int res = 0;
        while(x){
            res += tree[x];
            x -= lowbits(x);
        }
        return res;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        ll sums = 0;
        vector<ll> preSum = {0};
        for(int x : nums){
            sums += x;
            preSum.emplace_back(sums);
        }

        set<ll> st;
        for(auto x : preSum){
            st.insert(x - lower);
            st.insert(x);
            st.insert(x - upper);
        }

        // 离散化
        unordered_map<ll, int> p;
        int c = 0;
        for(auto x : st) p[x] = c++;

        int res = 0;
        n = p.size();
        tree = vector<int> (n+5, 0);
        // cout << n << endl;
        for(auto x : preSum){
            int left = p[x-upper], right = p[x-lower];
            res += query(right+1) - query(left);
            // cout << x << " " << right << " " << query(right+1) << " " << left << " " << query(left) << endl;
            update(p[x]+1);
        }
        return res;
    }
};
```



