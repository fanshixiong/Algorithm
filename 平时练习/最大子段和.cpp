// 最大子段和
//dp[i]为到i为止最大子段和包括i : dp[i] = max(nums[i], dp[i-1] + nums[i]);
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	vector<int> dp(n+1);
	//************************************j简单dp///////////////////////// 
	int tmp = -0x3f3f3f3f, maxr = -0x3f3f3f3f;
	for (int i = 0; i < n; i++){
		tmp = max(nums[i]+tmp, nums[i]);
		if (tmp > maxr)
			maxr = tmp; 
	}
	//************************************dp/////////////////////////////
	dp[0] = nums[0]; 
	for (int i = 1; i < n; i++)
		dp[i] = max(nums[i], nums[i] + dp[i-1]);
	//cout << maxr << *max_element(dp.begin(), dp.end());
	cout << maxr <<endl;
	return 0;
} 
