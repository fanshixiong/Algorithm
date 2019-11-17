#include <iostream>
#include <vector>
using namespace std;

//   e1 e2 表示装配站所需时间
//   x1，x2表示出站时间
//   a1 a2 表示各个装配站花费时间	
//   t1 t2 各个装配线间转移花费时间
//   装配线间的最优线路保存在l1和l2中
//   f1 f2 保存了前面所有的最优解
#define SIZE 6
int e1 = 2, e2 = 4;
int a1[] = {7, 9, 3, 4, 8, 4};
int a2[] = {8, 5, 6, 4, 5, 7};
int t1[] = {2, 3, 1, 3, 4};
int t2[] = {2, 1, 2, 2, 1};
int x1 =3, x2 = 2;


void print_path (vector<int> &l1, vector<int> &l2, int l, int j)
{
	if (j > 0)
	{
		if (l == 0)
			print_path (l1, l2, l1[j], j-1);
		else
			print_path (l1, l2, l2[j], j-1);
	}
	cout << l << "line, " << j << "station" << endl;
}
void fast_way ()
{
	vector<int> f1(SIZE), f2(SIZE);
	vector<int> l1(SIZE), l2(SIZE);
	f1[0] = a1[0] + e1;
	f2[0] = a2[0] + e2;
	int j = 1;
	for (j; j < SIZE; j++)
	{
		if (f1[j-1] < f2[j-1] + t2[j-1])
		{
			f1[j] = f1[j-1] + a1[j];
			l1[j] = 0;
		}
		else
		{
			f1[j] = f2[j - 1] + t2[j -1] + a1[j];
			l1[j] = 1;
		}
		if (f2[j-1] < f1[j-1] + t1[j - 1])
		{
			f2[j] = f2[j-1] + a2[j];
			l2[j] = 1;
		}
		else
		{
			f2[j] = f1[j-1] + t1[j-1] + a2[j];
			l2[j] = 0;
		}
	}

	int f, l;                                  //f为总的最优的解

	if (f1[j-1] + x1 < f2[j-1] + x2)
	{
		f = f1[j-1] + x1;
		l = 0;
	}else
	{
		f = f2[j-1] + x2;
		l = 1;
	}

	cout << f <<endl;
	print_path (l1, l2, l, SIZE-1);
}


void main ()
{
	fast_way();
}