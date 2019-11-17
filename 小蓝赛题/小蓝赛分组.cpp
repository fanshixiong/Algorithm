/*小蓝赛分组问题 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
int INF = 0x3f3f3f3f; 

int main(){
	long long n;  cin >> n;
	vector<long> nums(n);
	long long sum = 0;
	for (int i = 0; i < n; i++){
		cin >> nums[i];
		sum += nums[i];
	}
	sort(nums.begin(), nums.end());
	int min_x, max_x;
	cin >> min_x >> max_x;
	if (sum < min_x * n || sum > max_x*n){
		cout << -1 << endl;
		return 0;
	}
	long long res = 0;
	/*超时 
	while(1){
		if(nums[0] >= min_x && nums[nums.size()-1] <= max_x)
			break;
		for (int j = nums.size()-1; j >= 0; j--){
			int max_r = nums[nums.size()-1] - max_x;
			if (max_r > 0){
				nums[nums.size()-1] -= max_r;
				nums[0] += max_r;
				res += max_r;
			}
		}
		sort(nums.begin(), nums.end());
	}*/
	//res 判断是否全部都在边界内    top判断大于上界的人数， bottom判断小于下届的人数 
	long long top = 0, bottom = 0;
	for (int i = 0; i < nums.size(); i++){
		res += max(max(nums[i]-max_x, (long)0), min_x - nums[i]);
		if (nums[i] < min_x){
			bottom += min_x-nums[i];
		} 
		else if(nums[i] > max_x){
			top += nums[i]-max_x;
		} 
	}
	if (res == 0)
		cout << res << endl;
	else
		cout << max(top, bottom) << endl;
	return 0;
}
