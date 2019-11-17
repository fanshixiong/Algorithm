// 在一组数中找出最小的移动步数，使得所有元素值相等，可以同时移动多台机器 
//分析：以k为中间点，求出左边与平均值的差，和右边所有元素与平均值的差，
//      若left与right均小于零，说明此刻需要将第k个洗衣机的衣服移动到左右两边去，但是不能同时及进行，所以res = max(res, 0-left-right);
//      若钧大于零，说明此刻 需要将两边的移动到中间去，可以同时进行， res = max(res, max(left, right));
//      另外，若都不满足，说明需要将第k个洗衣机一侧衣服经k移动到另一侧，res =  max (res, max(abs(left), abs(right)));

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int findMinMove(vector<int> &nums){
	if (nums.size() == 0) return -1;
	vector<int> sum(nums.size()+1);
	for (int i = 1; i <= nums.size(); i++)
		sum[i] = sum[i-1] + nums[i-1];
	if (sum[nums.size()] % nums.size() != 0) return -1;
	int ave = sum[nums.size()] / nums.size();
	int res = -0x3f3f3f3f;
	for (int i = 0; i < nums.size(); i++){
		int left = sum[i]-ave*i;
		int right = (sum[nums.size()] - sum[i+1]) - (nums.size()-i-1)*ave;
		if (left < 0 && right < 0)
			res = max(res, 0-left-right);
		else if (left > 0&& right > 0)
			res = max(res, max(left, right));
		else
			res = max (res, max(abs(left), abs(right)));
	}
	return res;
}
int main(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	cout << findMinMove(nums) << endl;
	return 0;
} 
