#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class IntervalTree{
	vector<int> tree;
	int maxn;              //���Ԫ�� 
	public:
		IntervalTree (){
			tree.resize(0); maxn = 0; 
		}
		IntervalTree (vector<int> &nums){
			maxn = 100;
			tree.resize(maxn, 0); 
		}
		int lowbit(int i){
			return i & (-i);
		}
		void add(int i, int x){
			while (i <= maxn){
				tree[i] += x;
				i += lowbit(i);
			}
		}
		
		int sum (int x){
			int res = 0;
			while (x > 0)
			{
				res += tree[x];
				x -= lowbit(x);
			}
			return res;
		}
		
		int resultreversePairs (vector<int> &nums){                   //��ɢ������ ��������Ԫ��ֵ�ǳ�������   ������ӳ��˼�� 
			int res = 0;
			int *tp = new int[nums.size()];
			for (int i = 0; i < nums.size(); i++)
				tp[i] = nums[i];
			sort (tp, tp+nums.size());              //����ɢ��������
			unique (tp, tp+nums.size());            //ȥ��  ����ɢ����ȥ�� unique��������

			for (int i = 0; i < nums.size(); i++)
			{
				int num = lower_bound (tp, tp+nums.size(), nums[i]) - tp + 1;
				add (num, 1);
				res += i - sum(num) + 1;
			}
			return res;
		}
};


int main()
{
	vector<int> nums;
	//nums.push_back(5);
	nums.push_back(4);
	nums.push_back(3);
//	nums.push_back(6);
	nums.push_back(2);
	nums.push_back(1); 
	IntervalTree test (nums);
	int sums = test.resultreversePairs(nums);
	cout << sums;
	return 0;
 } 
