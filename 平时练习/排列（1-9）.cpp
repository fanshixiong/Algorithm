
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main()
{
	vector <int> a(10, 0);
	int count = 0;
	int abc, def, ghi;
	
	for (abc = 123; abc < 329; abc++)
	{
		for (int i = 1; i < 10; i++)
		a[i] = 0;
		def = abc * 2;
		ghi = abc * 3;
		
		a[abc % 10] = a[(abc / 10) % 10] = a[abc / 100] = 1;
		a[def % 10] = a[(def / 10) % 10] = a[def / 100] = 1;
		a[ghi % 10] = a[(ghi / 10) % 10] = a[ghi / 100] = 1;
		
		for (int i = 1; i < 10; i++)
			count += a[i];
		if (count == 9)
			cout << abc << " " << def << " " << ghi << " " << endl;
		count = 0;
		 
		
	}
	return 0;
}
