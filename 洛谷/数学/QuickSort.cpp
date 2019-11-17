#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> nums(100000+5);
int Partition(int left, int right){
	int temp=nums[left];
	while(left < right){
		while(left<right && nums[right]>=temp)right--;
		if(left<right) nums[left++]=nums[right];
		while(left<right && nums[left]<=temp)left++;
		if(left<right) nums[right--]=nums[left];
		
	}
	nums[left]=temp;
	return left;
}
void QuickSort(int left, int right){
	if(left<right){
		int mid=Partition(left, right);
		QuickSort(left, mid-1);
		QuickSort(mid+1, right);
	}
}
int main(){
	int n; cin >> n;
	for(int i=1; i<=n; i++)
		cin >> nums[i];
	//QuickSort(1, n);
	sort(nums.begin()+1, nums.begin()+n+1);
	for(int i=1; i<=n; i++)
		cout << nums[i] << " ";
	cout << endl; 
	return 0;
}
