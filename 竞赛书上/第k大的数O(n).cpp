/*随机选择算法：即求数组中第k个元素的值 , 此算法时间复杂度 n 
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;
void swap(vector<int> &nums, int x, int y){
	int tmp = nums[x];
	nums[x] = nums[y];
	nums[y] = tmp;
}
int randPartition(vector<int> &nums, int left, int right){
	int p = (round(1.0 * rand())/RAND_MAX * (right-left)+left);
	swap(nums, left, p);
	int temp = nums[left];
	while (left <right){
		while (left < right && nums[right] > temp) right--;
		nums[left] = nums[right];
		while (left <right && nums[left] < temp) left++;
		nums[right] = nums[left];
	}
	nums[left] = temp;
	return left;
}
void randSelect(vector<int> &nums, int left, int right, int k){
	if (left == right) return;
	int p = randPartition(nums, left, right);
	int m = p-left+1;
	if (k == m) return;
	if (k < m)
		randSelect(nums, left, p-1, k);
	else
		randSelect(nums, p+1, right, k-m);
	return;
}
int main(){
	srand((unsigned)time(NULL));
	freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	randSelect(nums, 0, n-1, n/2);
	cout << nums[n/2-1] <<endl;
	return 0;
} 
