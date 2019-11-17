#include <iostream>
#include <multiset>
using namespace std;

bool Trupike (int X[], multiset<int> D, int N)
{
	X[1] = 0;
	auto it = D.end ();
	X[N] = *(--it);
	--it;
	D.erase (X[N]);
	X[N-1] = *(it);
	D.erase (X[N-1]);

	if (it = D.find (X[N] - X[N - 1]) != D.end ())
	{
		D.erase (it);
		return Place (X, D, N, 2, N-2);
	}
	return 0;
}

bool Place (int X[], multiset<int> D, int N, int left, int right)
{
	bool found = false;
	if (D.empty ())
		return flase;
	auto it = D.end();
	--it;
	X[right] = *it;

	int i, j;
	for (i = 1; i <left; i++)
	{
		if ((it = D.find (X[right] - X[i])) != D.end())
			D.erase (it);
		else 
		{
			for (int k = i - 1; k > 0; k--)
				D.insert (X[right] - X[i]);
			break;
		}
	}
	if (i == left)
	{
		for(i=right+1; i<=N; i++)
		{
			if((it = D.find (X[i] - X[right])) != D.end ())
				D.erase (it);
			else
			{
				for (int k = i - 1; k > right; k--)
					D.insert (X[k] - X[right]);
				break;
			}
		}
	
		if (i == N+1)
		{
			found = Place (X, D, N, left, right - 1);
			if (!found)
			{
				for (i = 1; i < left; i++)
					D.insert (X[right] - X[i]);
				for (i = right+1; i <= N; i++)
					D.insert (X[i] - X[right]);
			}
			else
			return true;
		}
	}
	X[left] = X[N] - X[right];
	for (i = 1; i <left; i++)
	{
		if ((it = D.find (X[left] - X[i])) != D.end())
			D.erase (it);
		else 
		{
			for (int k = i - 1; k >= 0; k--)
				D.insert (X[left] - X[k]);
			break;
		}
	}
	if (i == left)
	{
		for(i = right + 1; i<=N; i++)
		{

			if ((it = D.find (X[i] - X[right])) != D.end ())
			D.erase (it);
			else
			{
				for (int k =1; k <left; k++)
					D.insert (S[left] - X[k]);
				for (int k = i - 1; k > right; k--)
					D.insert (X[k] - X[left]);
				break;
			}
		}
	
		if (i == N+1)
		{
			found = Place (X, D, N, left+1, right);
			if (!found)
			{
				for (i = 1; i < left; i++)
					D.insert (X[left] - X[i]);
				for (i = right+1; i <= N; i++)
					D.insert (X[i] - X[left]);
			}
			else
				return true;
		}
	}
	return false;

}

