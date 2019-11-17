//蓝桥杯球票问题：约瑟夫环 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >>n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	int res = 0, max_res = 0;
	for (int i = 0; i < n; i++){
		int j = 0, k = i, count = 0;
		res = 0;
		vector<bool> vis(n, 0);
		int maxa = nums[i];
		while(j <= maxa){
			if (count >= n)
				break;
			maxa = max(maxa, nums[k]);
			if (nums[k] == j+1 && !vis[k]){
				res += nums[k];
				vis[k] = 1;
				j = 0;k++;
				count++;
			}
			else if(!vis[k]){
				j++;k++;
			}
			else k++;
			if (k >= n)
				k = (k+n)%n;
		}
		max_res = max(res, max_res);
	}
	cout << max_res;
	return 0;
}
