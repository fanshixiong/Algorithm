// ��һ�������ҳ���С���ƶ�������ʹ������Ԫ��ֵ��ȣ�����ͬʱ�ƶ���̨���� 
//��������kΪ�м�㣬��������ƽ��ֵ�Ĳ���ұ�����Ԫ����ƽ��ֵ�Ĳ
//      ��left��right��С���㣬˵���˿���Ҫ����k��ϴ�»����·��ƶ�����������ȥ�����ǲ���ͬʱ�����У�����res = max(res, 0-left-right);
//      ���������㣬˵���˿� ��Ҫ�����ߵ��ƶ����м�ȥ������ͬʱ���У� res = max(res, max(left, right));
//      ���⣬���������㣬˵����Ҫ����k��ϴ�»�һ���·���k�ƶ�����һ�࣬res =  max (res, max(abs(left), abs(right)));

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
