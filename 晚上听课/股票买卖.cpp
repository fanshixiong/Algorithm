//LeetCode123  股票买卖问题：大意：给一个数组代表每个股票的价值，你可以在一天买入，在随后的几天卖出（卖出前必须买入股票），可以当天买当天卖，求交易k次的最大利益。

//分析：如果k为2，那么会有很多种思路。
//1.	可以将两次交易转换为一次交易，即在判断第i天的交易利益的时候，计算出第i天截至时的一次交易的最大利益以及从第i天开始至结束的最大利益。那么通过判断每一天的两次交易的最大利益就可求出最大利益。
//读者可以想到：这是一个O(n2)的算法，其实不然，可以通过两次遍历，一次从前往后，找到到第i天为止交易一次的最大利益。一次从后往前，找到第i天之后的一次交易的最大利益。最后再找到最大交易两次的利益。具体做法参考代码：


//2. 动态规划：（全局最优和局部最优）
//	尽管上面的做法看上去不错，但是扩展到k此交易，上面的方法就肯定做不了的。我们维护两个动态规划方程
 


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> left(n);
	    vector<int> right(n);
	    int minl = 0x3f3f, resl = 0;
	    for (int i = 0; i < n; i++){
		    if (minl > prices[i])
			    minl = prices[i];
		    int dis  = prices[i] - minl;
		    if (dis  > resl)
			    resl = dis;
    		left[i] = resl;
	    }
	    int maxr = 0, resr = 0 , res = 0, dis;
	    for (int i = n-1; i>=0; i--){
		    if (maxr < prices[i])
			    maxr = prices[i];
    		int dis = maxr - prices[i];
	    	if (dis > resr)
		    	resr = dis;
    		right[i] = resr;
            dis = left[i] +right[i];
            if (res < dis)
                res = dis;
        }
        return res;
    }
int main(){
	freopen("in.txt", "r", stdin);
	int n;
	cin >>n;
	vector<int> nums(n);
	for (int i = 0; i < nums.size(); i++)
		cin >> nums[i];

	cout << maxProfit(nums) <<endl;
	return 0; 
}
