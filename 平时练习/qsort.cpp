#include <iostream> 
#include <cassert>
using namespace std;

void swap (int i, int j, int a[])
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int partition (int p, int r, int a[])
{
	int i = p, j = r + 1;
	int x = a[p];
	while (true)
	{
		while (++i && a[i] < x && i < r);
		while (--j && a[j] > x);
		if (i >= j)
			break;
		swap (i, j, a);
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}


int random (int p, int r, int a[])
{
	assert (a);
	int mid = p + (r - p) >> 1;
	if (a[p] <= a[r])
	{
		if (a[mid] < a[p])
			swap (mid, p, a);
		if (a[mid] > a[r])
			swap (mid, r, a);
	}
	else
	{
		if (a[p] < a[mid])
			swap (p, mid, a);
		if (a[mid] < a[r])
			swap (r, mid, a);
	}
	return mid;
}
int randomPartition (int p, int r, int a[])
{
	int i = random (p, r, a);
	swap (p, i, a);
	return partition (p, r, a);
}

void qSort (int p, int r, int a[])
{
	if (p < r){
		int q = randomPartition (p, r, a);
		qSort (p, q-1, a);
		qSort (q+1, r, a);
	}
}

int main ()
{
	int a[] = {15, 52, 16, 87, 45, 51, 49, 28, 38, 68, 33, 39, 42, 15, 9};
	qSort (0, 14, a);
	for (int i = 0; i < 14; i++)
	cout << a[i] << "\t" ;
	cout << endl;
	return 0;
}
