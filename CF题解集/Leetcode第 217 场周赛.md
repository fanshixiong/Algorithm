# Leetcode第 217 场周赛

比赛链接：[点这里](https://leetcode-cn.com/contest/weekly-contest-217/)

~~做完前两题我就知道今天的竞赛我已经结束了~~

这场比赛思维量还是比较大的。



### [1673. 找出最具竞争力的子序列](https://leetcode-cn.com/problems/find-the-most-competitive-subsequence/)

**题目**

给你一个整数数组 `nums` 和一个正整数 `k` ，返回长度为 `k` 且最具 **竞争力** 的 `nums` 子序列。

数组的子序列是从数组中删除一些元素（可能不删除元素）得到的序列。

在子序列 `a` 和子序列 `b` 第一个不相同的位置上，如果 `a` 中的数字小于 `b` 中对应的数字，那么我们称子序列 `a` 比子序列 `b`（相同长度下）更具 **竞争力** 。 例如，`[1,3,4]` 比 `[1,3,5]` 更具竞争力，在第一个不相同的位置，也就是最后一个位置上， `4` 小于 `5` 。

**示例 1：**

```
输入：nums = [3,5,2,6], k = 2
输出：[2,6]
解释：在所有可能的子序列集合 {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]} 中，[2,6] 最具竞争力。
```

**示例 2：**

```
输入：nums = [2,4,3,3,5,4,9,6], k = 4
输出：[2,3,3,4]
```

 

**提示：**

-   $1 <= nums.length <= 10^5$
-   $0 <= nums[i] <= 10^9$
-   $1 <= k <= nums.length$



#### 思路

比赛时想到了单调栈，但是不熟不敢写( 还得练练。。

随便写了一通居然过了。

思路是找到数组中的最小值`mi`，那么最后的结果中肯定有这个值，如果`mi`所在的位置`p`之后的元素个数不足`k`个了，那么`p`之后的元素肯定都是要的，因为没有比它们更小的了，但是此时元素个数不够，那么就需要在`p`之前的元素的中找剩下的元素。这不就是个子问题么，直接递归完事儿。

**代码**

```cpp
class Solution {
public:
    vector<int> vis;
    void helper(vector<int>& nums, int k, int l, int r){
        if(l > r || k <= 0) return;
        
        // 最小值
        int p;
        int minn = 0x3f3f3f3f;
        for(int i = l; i <= r; i++){
            if(minn > nums[i]){
                minn = nums[i];
                p = i;
            }
        }
        vis[p] = 1;
        int t = r-p;
        // 剩下元素个数大于k，直接在k后面找剩下的元素，因为此位置一定是最小的。
        if(t >= k) {
            helper(nums, k-1, p+1, r);
        }
        else {
            //剩下元素没有k个
            for(int i = p+1; i <= r; i++) vis[i] = 1;
            helper(nums, k-t-1, l, p-1);
        }
    }
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        if(!nums.size() || nums.size() < k) return vector<int>();
        if(k == nums.size()) return nums;
        
        vector<int> t = nums;
        sort(t.begin(), t.end());
        if(t == nums){
            return vector<int> (nums.begin(), nums.begin()+k);
        }
        
        vis = vector<int> (nums.size(), 0); //记录答案
        
        helper(nums, k, 0, nums.size()-1);
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(vis[i]) ans.push_back(nums[i]);
        }
        return ans;
    }
};
```



#### 正解

单调栈维护栈顶元素比当前元素小。

弹栈当且仅当栈顶元素比当前元素大并且保证栈中元素加上剩余元素能够凑够k个。



`巨坑：vector .size()方法一定要加(int), 这个错误不好找，也想不到。`

![image-20201130155043129](\Leetcode第 217 场周赛.assets\image-20201130155043129.png)

以示警醒。

代码逻辑还是比较简单的。

**代码**

```cpp
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> st;
        for(int i = 0; i < nums.size(); i++){
            int c = nums[i];
            while(!st.empty() && st.back() > c &&  k - (int)st.size() + 1 <= (int)nums.size() - i) st.pop_back();
            st.push_back(c);
        }

        while(st.size() > k) st.pop_back();
        return st;
    }
};
```



`PS：`这道题跟[402. 移掉K位数字](https://leetcode-cn.com/problems/remove-k-digits/)这道有异曲同工之妙，不同点在于一个是删除k个数，一个是留下k个数，但是思路大题一致，可以对比着来学。~~是的，做过的题记不住。ε=(´ο｀*)))~~





### [1674. 使数组互补的最少操作次数](https://leetcode-cn.com/problems/minimum-moves-to-make-array-complementary/)

**题目**

给你一个长度为 **偶数** `n` 的整数数组 `nums` 和一个整数 `limit` 。每一次操作，你可以将 `nums` 中的任何整数替换为 `1` 到 `limit` 之间的另一个整数。

如果对于所有下标 `i`（**下标从** `0` **开始**），`nums[i] + nums[n - 1 - i]` 都等于同一个数，则数组 `nums` 是 **互补的** 。例如，数组 `[1,2,3,4]` 是互补的，因为对于所有下标 `i` ，`nums[i] + nums[n - 1 - i] = 5` 。

返回使数组 **互补** 的 **最少** 操作次数。

**示例 1：**

```
输入：nums = [1,2,4,3], limit = 4
输出：1
解释：经过 1 次操作，你可以将数组 nums 变成 [1,2,2,3]（加粗元素是变更的数字）：
nums[0] + nums[3] = 1 + 3 = 4.
nums[1] + nums[2] = 2 + 2 = 4.
nums[2] + nums[1] = 2 + 2 = 4.
nums[3] + nums[0] = 3 + 1 = 4.
对于每个 i ，nums[i] + nums[n-1-i] = 4 ，所以 nums 是互补的。
```

**示例 2：**

```
输入：nums = [1,2,2,1], limit = 2
输出：2
解释：经过 2 次操作，你可以将数组 nums 变成 [2,2,2,2] 。你不能将任何数字变更为 3 ，因为 3 > limit 。
```

**示例 3：**

```
输入：nums = [1,2,1,2], limit = 2
输出：0
解释：nums 已经是互补的。
```

 

**提示：**

-   $n == nums.length$
-   $2 <= n <= 10^5$
-   $1 <= nums[i] <= limit <= 10^5$
-   $n$ 是偶数。



#### 思路

~~完全没有思路，题刷得还是太少了啊~~

差分+前缀和

首先我们知道答案最大是$n$, 这是将所有的数字都改了的情况。

假设数组中互补的两元素为$A$和$B$，

我们用$delta[i]$ 表示将$A+B$改为$i$时需要的操作次数，那么就可以分为以下五种情况：

*   $2<=i<=min(A, B)$: 需要两次操作
*   $min(A, B)+1<=i<=max(A, B) + 1$： 需要一次操作
*   $i == A+B$: 不需要操作
*   $A+B+1<=i<=limit + max(A, B)$: 需要一次操作
*   $i > limit + max(A, B)$: 需要两次操作

但是知道了这么多种情况，怎么来表示他们之间的变化以及求和呢？

答案是使用差分数组，只需要改变被改变区间的边界的两个值，就可以在$O(n)$的时间里求和。



**代码**

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> delta(limit*2+20, 0);
        int n = nums.size();
        delta[0] = n; //开始为n次操作
        unordered_map<int, int> freq;
        for(int i = 0; i < n/2; i++){
            int sums = nums[i] + nums[n-i-1];
            int lo = 1 + min(nums[i], nums[n-i-1]);
            int hi = limit + 1 + max(nums[i], nums[n-i-1]);

            // 差分
            delta[lo] --;
            delta[sums]--;
            delta[sums+1] ++;
            delta[hi]++;
        }

        //求和
        for(int i = 1; i <= limit*2; i++) delta[i] += delta[i-1];
        int ans = 0x3f3f3f3f;
        for(int i = 1; i <= limit*2; i++){
            ans = min(ans, delta[i]);
        }
        return ans;
    }
};
```









### [1675. 数组的最小偏移量](https://leetcode-cn.com/problems/minimize-deviation-in-array/)

**题目**

给你一个由 `n` 个正整数组成的数组 `nums` 。

你可以对数组的任意元素执行任意次数的两类操作：

-   如果元素是偶数，除以$2$
    -   例如，如果数组是 `[1,2,3,4]` ，那么你可以对最后一个元素执行此操作，使其变成 `[1,2,3, 2]`
-   如果元素是奇数，乘上$2$
    -   例如，如果数组是 `[1,2,3,4]` ，那么你可以对第一个元素执行此操作，使其变成 `[2,2,3,4]`

数组的 **偏移量** 是数组中任意两个元素之间的 **最大差值** 。

返回数组在执行某些操作之后可以拥有的 **最小偏移量** 。

**示例 1：**

```
输入：nums = [1,2,3,4]
输出：1
解释：你可以将数组转换为 [1,2,3,2]，然后转换成 [2,2,3,2]，偏移量是 3 - 2 = 1
```

**示例 2：**

```
输入：nums = [4,1,5,20,3]
输出：3
解释：两次操作后，你可以将数组转换为 [4,2,5,5,3]，偏移量是 5 - 2 = 3
```

**示例 3：**

```
输入：nums = [2,10,8]
输出：3
```

 

**提示：**

-   $n == nums.length$
-   $2 <= n <= 105$
-   $1 <= nums[i] <= 10^9$



#### 思路

~~又是智商被吊打的一题~~

优先队列

我们考虑维护大根堆，将所有数先化为最大的形式(也就是奇数$*2$)，加入大根堆，维护 $mi$ 表示当前堆的最小值。

之后我们不断地取出堆顶，也就是当前堆最大的数，除$2$，重新加入大根堆，此过程中不断更新答案。

当堆顶为奇数时，就说明不能再除以$2$，最大值不可能再缩小，答案也就不会再被缩小。



**代码**

```cpp
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> q; //大根堆
        int mi = INT_MAX;
        for(auto x : nums){
            if(x&1) x <<= 1; //奇数乘2加入
            q.push(x);
            mi = min(mi, x);
        }
        int ans = INT_MAX;
        while(1){
            auto x = q.top();
            q.pop();
            ans = min(ans, x-mi);
            if(x&1) break; //最大值奇数直接退出
            x >>= 1;
            q.push(x);
            mi = min(x, mi); //维护mi为当前堆中的最小值
        }
        return ans;
    }
};
```

