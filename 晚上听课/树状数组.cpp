#include <iostream>
#include <vector>
using namespace std;

class IndexTree {
	vector<int> bit;
	vector<int> cf; //�������1 ά��bit[i]�Ĳ��� 
	vector<int> cf2;  //�������2 ά��bit[i] * i���� 
	int n;
	public:
		IndexTree (){
			bit.resize(0);
			cf.resize(0);
			cf2.resize(0);  
		}
		IndexTree (vector <int> nums){
			bit.resize(nums.size()+1, 0);
			cf.resize(nums.size() + 1, 0); 
			cf2.resize(nums.size() + 1, 0);
			n = nums.size();
			for (int i = 0; i < nums.size(); i++)
				add (i+1, nums[i]);
				 
		}
		int lowbit (int x)
		{
			return x & (-x);
		}

		int sum ( int x) // ������� 1 �� x 
		{
			int res = 0;
			while (x > 0)
			{
				res += bit[x];
				x -= lowbit(x);
			}
			return res;
		}
		int getsum (int x, int y)
		{
			return sum(y) - sum(x-1);
		}
		int intervalsum (int n)  //��ѯǰn��ĺ�                  
		{
			int res = 0;
			while ( n > 0)
			{
				res += cf[n] *  (n + 1) - cf2[n];
				n -= lowbit(n);
			}
			return res;
		} 
		int getintervalsum (int x, int y)
		{
			return sum(y) - sum (x-1);
		}
		void add (int i, int x)         //�����޸ļ������ѯ cf cf2������� 
		{
			while (i <= n)
			{
				bit[i] += x;
				cf[i] += x;
				cf2[i] += x * i;
				i += lowbit(i);
			}		
		}
		void sub (int i, int x)
		{
			while (i <= n)
			{
				bit[i] -= x;
				cf[i] -= x;
				cf2[i] -= x * i;
				i += lowbit(i);
			}	
		}
	
		void print (){
			for (int i = 1; i < bit.size(); i++)
				cout << bit[i] << "\t";
			cout << endl;
		}
};

int main ()
{
	vector <int> nums;
/*	for (int i = 0; i < 6; i++)
		nums.push_back(i+2); 
	for (int i = 0; i < 6; i++)
		cout << nums[i] << "\t";
	cout << endl;	*/
	nums.push_back(2);
	nums.push_back(-1);
	nums.push_back(2);    
	IndexTree test (nums);

	test.print() ;
	return 0;
}

