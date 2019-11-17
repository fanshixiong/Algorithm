//这是一个区逆序对的个数的算法，用到的知识有二叉搜索树 归并排序
// 第一次的思路为什么错了？ 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int reversePairs (vector<int> &nums,vector<int> &tmp,  int beg, int end);
 int reversePairs (vector<int> &nums, vector<int> &tmp, int beg, int end)
 {
 	if (beg == end)
 		return 0;
 	int mid = beg + (end - beg) / 2;
 	int left = reversePairs(nums, tmp, beg, mid);
 	int right = reversePairs(nums, tmp, mid+1, end);
 	int count = 0;

 	
 	int i = beg, j = mid+1, k = beg;
 	while (i <= mid && j <= end)
 	{
 		double x = nums[i] * 0.5, y = nums[j];
 		if (x > y)
 		{
 			count += mid-i+1;
 			j++;
		 }
		 else
		 i++;
	}
	i = beg; j = mid+1;

	while(i <= mid && j <= end)
	{
		if (nums[i] <= nums[j])
			tmp[k++] = nums[i++];
		else
			tmp[k++] = nums[j++];
	}
	while(i <= mid)
		tmp[k++] = nums[i++];
	while (j <= end)
		tmp[k++] = nums[j++];

	for (i = 0; i <= end; i++)
		nums[i] = tmp[i];
		
	
	return (left + right + count);
 }
 
 int main ()
 {
 	vector<int> a;
 	a.push_back(5);
 	a.push_back(6);
 	a.push_back(2);
 	a.push_back(1);
	a.push_back(3);
	a.push_back(2);   
 	vector <int> b(a);
 	int n = reversePairs(a, b, 0, a.size()-1);
 	cout << n << endl;
 	return 0;
 }
