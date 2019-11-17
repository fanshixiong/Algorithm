#include <iostream>
#include<vector>
using namespace std;

int MaxSumBinary (int left, int right, vector<int> &num)
{
	int sum = 0;
	if (left == right) {
		sum = num[left] > 0 ? num[left] : 0;
		return sum;
	}
	else
	{
		int mid = left + (right - left) / 2;
		int leftsum = MaxSumBinary (left, mid, num);
		int rightsum = MaxSumBinary (mid+1, right, num);
	
		int xl = 0, suml = 0;
		for (int i = mid; i >= left; i--)
		{
			xl += num[i];
			if (suml < xl)
				suml = xl;
		}
		int xr = 0, sumr = 0;
		for (int i = mid+1; i <= right; i++)
		{	
			xr += num[i];
			if (xr > sumr)
				sumr = xr;
		}
	}
	sum = sumr + suml;
	sum = sum < leftsum ? leftsum : sum;
	sum = sum < rightsum ? rightsum : sum;

	return sum;
}
int MaxSum(int n, vector<int> &num)
{
	int sum = 0, b = 0;
	for (int i = 0; i < num.size(); i++)
	{
		if (b > 0)
			b += num[i];
		else
			b = num[i];
		if (b > sum)
			sum = b;
	}
	return sum;
}
int main()
{
	vector<int> num;
	for (int i = 0; i < 5; i++)
		num.push_back(i+3);
	num.push_back(-5);
	num.push_back(-3);
	for(int i = 0; i < 3; i++)
		num.push_back(i-2);
//	cout << MaxSum (num.size() , num) << endl;
	cout << MaxSumBinary (0, num.size()-1, num) << endl;    
	return 0;
}
