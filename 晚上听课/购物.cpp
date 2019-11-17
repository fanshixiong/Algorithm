// 2018.12.13
//周四晚 周天行  超市和邮局

//超市：有一天，鱼牛去超市买东西，他买东西有个很奇怪的特性：他买一件东西的价格一定要比上一件的低。
//现在给出超市里东西的价格，请问鱼牛如何选择才能购买到最多的东西呢？并请求出鱼牛买东西的方案数。 

//分析：第一问为最长递减子序列的问题，简单的dp，f[i] = max(f[j]) + 1, ( 1 <= j < i < n )
//关键在第二问的处理 : 假设p[i]是最长子序列的最后一个元素（即max(f[i])的情况）的方案数，则状态转移方程：p[i] =  max(p[j)+p[i] (j满足f[j] = f[i]-1)

#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

int main(){
	freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++){
		cin >> nums[i];
	}
	vector<int> f(n, 1), p(n, 1);
	for (int i = 0; i < n; i++){
		for (int j = i-1; j >= 0; j--){
			/*if (nums[i] == nums[j]){
				p[i] = 0;
			}*/
			if(nums[i] < nums[j]){
				if (f[i] == f[j] + 1)
					p[i] += p[j]; 
				else if(f[i] < f[j] + 1){
					f[i] = f[j] + 1;
					p[i] = p[j];
				}
			}
		}
	}
	int max = *max_element(f.begin(), f.end());
	int res = 0;
	for (int i = 0; i < n; i++){
		if (f[i] == max)
			res += p[i];
	}
	cout << max << " " <<res<<endl;
	return 0;
}
