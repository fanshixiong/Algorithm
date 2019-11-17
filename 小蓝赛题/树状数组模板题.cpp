/*小蓝赛：找中间的数，使得左边的数比他小 右边的数比他大
分析： 树状数组，注意数据范围，long long 
*/
#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
class Tree{
	long long n;
	vector<long long> bit;
	vector<long long> nums; 
public: 
	Tree(){ 
		cin >> n;
		nums.resize(n+1);  
		for (long long i = 1; i <= n; i++){
			cin >> nums[i];
		}
	}
	int lowbit(long long x){
		return x&(-x);
	}
	void add(long long x){
		while(x <= n){
			bit[x]++;
			x += lowbit(x);
		}
	}
	long long sum(long long x){
		long long res = 0;
		while (x >= 1){
			res += bit[x];
			x -= lowbit(x);
		}
		return res;
	}
	void play(){
		vector<long long> left_min(n+1), right_min(n+1), left_max(n+1), right_max(n+1);
		bit.resize(n+1); 
		for (long long i = 1; i <= n; i++){
			left_max[i] = sum(nums[i]);
			add(nums[i]);
		}
		bit.clear();
		bit.resize(n+1); 
		for (long long i = n; i > 0; i--){
			right_max[i] = sum(nums[i]);
			add(nums[i]);
		}
		long long max_x = 0, min_x = 0;
		for (long long i = 1; i <= n; i++){
			max_x += left_max[i] * right_max[i];
		}
		
		for (long long i = 1; i <= n; i++)
			nums[i] = n-nums[i]+1;
		bit.clear();
		bit.resize(n+1); 
		for (long long i = 1; i <= n; i++){
			left_min[i] = sum(nums[i]);
			add(nums[i]);
		}
		bit.clear();
		bit.resize(n+1); 
		for (long long i = n; i >= 1; i--){
			right_min[i] = sum(nums[i]);
			add(nums[i]);
		}
		for (long long  i = 1; i <= n; i++)
			min_x += left_min[i] * right_min[i];
		
		cout << min_x << " " << max_x<<endl;
	}
};
int main(){
	Tree test;
	
	test.play();
	return 0;
}
