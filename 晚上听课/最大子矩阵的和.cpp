/*最大子矩阵和 
分析：道理同一维的子数组的和，把二维将为一维： 即求从第i行到第j行的每一列上的最大子数组的和 
注意：每一次更新i行时都要更新sum数组。 
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int maxsubArray(vector<int> nums){
	if (nums.size() == 0)  return 0;
	int res = 0;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++){
		if (sum < 0)sum = 0;
		else sum += nums[i];
		res = max(res, sum);
	}
	return res;
}
int MaxSumInMatrix(vector<vector<int> > &nums){
	if (nums.size() == 0 || nums[0].size() == 0) return -1;
	int res = 0;
	vector<int> sumij;                                   //从第i行到第j行的第k列的和
	for (int i = 0; i < nums.size(); i++){
		vector<int> sumij(nums[i].size());                           //每一次第i行更新的时候sumij数组都要更新；
		for (int j = i; j < nums.size(); j++){
			for (int k = 0; k < nums[0].size(); k++)
				sumij[k] += nums[j][k];
			res = max(res, maxsubArray(sumij)); 
		}
	}
	return res;
}
int main(){
	freopen("in.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > nums(n, vector<int>(m, 0));
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			cin >> nums[i][j];
		}
	cout << MaxSumInMatrix(nums) << endl;
	return 0;
} 
