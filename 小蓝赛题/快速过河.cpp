/*第六周 快速过河
分析： 思路最重要 可以分为几种情况：  
*/ 

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;
void Swap(vector<int> &nums, int x, int y){
	while (x <= y){
		int temp = nums[x];
		nums[x] = nums[y];
		nums[y] = temp;
		x++; y--;
	}
}
int main(){
	freopen("in.txt", "r", stdin);
	int n; cin >> n;
	while (n--){
		int m; cin >> m;
		vector<int> nums(m);
		for (int i = 0; i < m; i++)
			cin >> nums[i];
		sort(nums.begin(), nums.end());
		int res = 0;int i = m-1;
		for (; i > 2; i-=2){
			if (nums[0]*2 + nums[i]+nums[i-1] > nums[0] + nums[1]*2 + nums[i]){      //代表最小时间和次小时间过河之后再回来，最大时间和次大时间过河 
				res += nums[0] + nums[1]*2 + nums[i];
				cout << nums[0] << " " << nums[1] << endl;
				cout << nums[0] << endl;
				cout << nums[i] << " " << nums[i-1] << endl;
				cout << nums[1] << endl;
			}
			else{																			//代表最少时间拖着最大时间过河 
				res += nums[0]*2 + nums[i]+nums[i-1];
				cout << nums[0] << " " << nums[i] << endl;
				cout << nums[0] << endl;
				cout << nums[0] << " " << nums[i-1] << endl;
				cout << nums[0] << endl;
			}
		}
		if (i == 2){
			res += nums[0] + nums[1] + nums[2];
			cout << nums[0] << " " << nums[1] << endl;
			cout << nums[0] << endl;
			cout << nums[0] << " " << nums[2] << endl;
		}
		else if (i == 1){
			res += nums[1];
			cout << nums[0] << " " << nums[1] << endl;	
		}
		else{
			res += nums[0];
			cout << nums[0] << endl;
		}
		cout << res << endl << endl;
	}
	return 0;
}
