/*����Ӿ���� 
����������ͬһά��������ĺͣ��Ѷ�ά��Ϊһά�� ����ӵ�i�е���j�е�ÿһ���ϵ����������ĺ� 
ע�⣺ÿһ�θ���i��ʱ��Ҫ����sum���顣 
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
	vector<int> sumij;                                   //�ӵ�i�е���j�еĵ�k�еĺ�
	for (int i = 0; i < nums.size(); i++){
		vector<int> sumij(nums[i].size());                           //ÿһ�ε�i�и��µ�ʱ��sumij���鶼Ҫ���£�
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
