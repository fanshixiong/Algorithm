#include <iostream>
using namespace std;
static int p3 = 0, p5 = 0, p7 = 0;
long long min (long long x3, long long x5, long long x7)
{
	if (x3 < x5)
	{
		if (x3 < x7) 
		{
			p3++;
			return x3;
		}
		else if (x3 > x7)
		{
			p7++;
			return x7;
		}
		else
		{
			p3++;
			p7++;
			return x3;
		}
	}
	else if (x3 > x5)
	{
		if (x5 < x7)
		{
			p5++;
			return x5;
		}
		else if (x5 > x7)
		{
			p7++;
			return x7;
		}
		else
		{
			p7++;
			p5++;
			return x5;
		}
	}
	else
	{
		if (x3 < x7)
		{
			p3++;
			p5++;
			return x3;
		}
		else if ( x3> x7)
		{
			p7++;
			return x7;
		}
		else
		{
			p3++;
			p5++;
			p7++;
			return x3;
		}
	}
	
}
int main ()
{

	long long M = 59084709587505;
	long long dp[2200];

	dp[0] = 1;

	for (int i = 1; i < 2200; i++)
	{
		dp[i] = min (dp[p3] * 3, dp[p5] * 5, dp[p7] * 7);
		cout << dp[i] << endl;
		if (dp[i] == M)
			return i;
	}
	
	return 0;
}
