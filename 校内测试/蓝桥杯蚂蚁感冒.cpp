//蚂蚁感冒问题 ；  求蚂蚁问题的碰撞次数 

#include<iostream>
#include <vector> 
#include <cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	int left = 0, right = 0;
	for (int i = 1; i < n; i++){
		if (abs(nums[0]) < abs(nums[i]) && nums[0] < 0)
			left++;
		if (abs(nums[0]) > abs(nums[i]) && nums[0] > 0)
			right++;
	}
	int ans;
	if ((nums[0] < 0 && left == 0) || (nums[0] > 0 && right == 0))
		ans = 0;
	else
		ans = 1+left+right;
	cout << ans;
	return 0;
}
