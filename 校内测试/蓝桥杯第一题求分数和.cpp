#include <iostream>
using namespace std;

int main ()
{
	int i = 1, sum = 1;
	while (i < 20)
	{
		sum <<= 1;
		i++;
	}
	cout << sum * 2-1;
	return 0;
}
