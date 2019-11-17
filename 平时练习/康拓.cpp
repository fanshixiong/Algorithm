/*����չ�����濵��չ�� 
����չ������ȫ���������У��������һ�����У�������ȫ�����а��ֵ������еĵڼ������У� 
	������  ��ʽ��x = a[0]*(n-1)! + a[1]*(n-2)! + ... ... + a[n-1]*1! + a[n]*0!;  ���� ��a[i]��ָδ���ֵ�Ԫ���������еĴ���
	���ӣ�  1234��ȫ�����У�3214�ǵڼ������У�  x = 2*3! + 1*2! + 0*1! + 0*0! = 14;  ��Ϊ3��3214������б���С������2������0����ȥ��3��2�ŵ�1��������
�濵��չ������ȫ���������У��������������һ����Ȼ�������У�x
	������   ��x-1��/ (n-1)!  ��y������z ˵�����ڵ�һλǰ����y��Ԫ�ر���С����������
	���ӣ�  ��1234�� ��20��������ʲô��
	        19 / 3�� = 3...2 ˵�����ڵ�һλ��Ԫ��ǰ����3��Ԫ�ر���С ˵����һλ��4
			2  / 2�� = 1...0 ˵�����ڵڶ�λ��Ԫ��ǰ����1��Ԫ�ر���С ˵���ڶ�λ��2
			0  / 1�� = 0...0 ˵�����ڵ���λ��Ԫ��ǰ����0��Ԫ�ر���С ˵������λ��1
			...����λ��3 
���ã� ȫ�������⣬�ڶ��������������� 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int FAC[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
void cantor(){
	string target; cin >>target;
	vector<int> nums;
	int n = target.size();
	for (int i = 0 ; i < n; i++){
		nums.push_back(target[i]-'0');
	}
	int res = 0;
	for (int i = 0; i < n-1; i++){
		int small = 0;
		for (int j = i+1; j < n; j++)
			if (nums[i] > nums[j]) small++;
		res += small * FAC[n-i-1];
	}
	cout << res << endl;
} 
int decantor(){
	int n, x; cin >> n;
	vector<int> nums(n);
	vector<int> res;
	for (int i = 0; i < n; i++){
		cin >> nums[i];
	}
	cin >> x;
	int m = x-1, y = x-1;
	for (int i = 0; i < n; i++){
		m = y / FAC[n-i-1];
		y = y % FAC[n-i-1];
		sort(nums.begin(), nums.end());
		res.push_back(nums[m]);
		nums.erase(nums.begin() + m); 
	}
	for (int i = 0; i < n; i++)
		cout << res[i];
	cout << endl;
}
int main(){
	cantor();
	decantor();
	return 0;
} 
