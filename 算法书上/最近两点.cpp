#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;


class PointX{
	public:
		int ID;
		float x, y;
		int operator <= (PointX a) const
		{
			return x <= a.x;
		}
		void create(float a, float b, int i){
			ID = i;
			x = a;
			y = b;
		}
};
class PointY{
	public:
		int p;    //记录了该点对在数组X中的下标 
		float x, y; 
		int operator <= (PointY a)const
		{
			return y <= a.y;
		}
		void create(float a, float b, int i){
			p = i;
			x = a;
			y = b;
		}
};

float dist (const PointX& u, const PointX& v)
{
	float dx = u.x - v.x;
	float dy = u.y - v.y;
	return sqrt (dx * dx + dy * dy);
}


// 归并排序

void Merge1 (vector<PointX> &a, vector<PointX> &b, int s, int m, int t)
{
	int i = s;
	int j = m + 1, k = s;
	while (i <= m && j <= t)
	{
		if (a[i].x <= a[j].x)
			b[k++] = a[i++];
		else
			b[k++]  = b[j++];
	}	
	if (i <= m)
		while (i <= m)
			b[k++] = a[i++];
	else
		while (j <= t)
			b[k++] = a[j++];
}
void MergeSort1 (vector <PointX> &a, vector<PointX> &b, int s, int t)
{
	if (s == t)
	{
		b[s] = a[s];
		return;
	}
	else
	{
		int m = s + (t - s) / 2;

		MergeSort1(a, b, s, m);
		MergeSort1(a, b, m+1, t);
		Merge1 (a, b, s, m, t);
	}
} 

void Merge2 (vector<PointY> &a, vector<PointY> &b, int s, int m, int t)
{
	int i = s;
	int j = m + 1, k = s;
	while (i <= m && j <= t)
	{
		if (a[i].y <= a[j].y)
			b[k++] = a[i++];
		else
			b[k++]  = b[j++];
	}	
	if (i <= m)
		while (i <= m)
			b[k++] = a[i++];
	else
		while (j <= t)
			b[k++] = a[j++];
}
void MergeSort2 (vector <PointY> &a, vector<PointY> &b, int s, int t)
{
	if (s == t)
		b[s] = a[s];
	else
	{
		int m = s + (t - s)/ 2;
		MergeSort2(a, b, s, m);
		MergeSort2(a, b, m+1, t);
		Merge2 (a, b, s, m, t);
	}
} 


void closestPair (vector<PointX> &x, vector<PointY> &y, vector<PointY> &z, int l, int r, PointX &a, PointX &b, float &d)
{
	if (r - l == 1)
	{
		a = x[l]; b = x[r]; d = dist(x[l], x[r]); return;
	}
		
	if (r - l == 2)
	{
		float d1 = dist(x[l], x[l+1]);
		float d2 = dist(x[l+1], x[r]);
		float d3 = dist(x[r], x[l]);
		
		if (d1 <= d2 && d1 <= d3)
		{
			a = x[l]; b = x[l+1]; d = d1;
		}
		else if (d2 <= d1 && d2 <= d3)
		{
			a = x[l+1]; b = x[r]; d = d2;;
		}
		else
		{
			a = x[l]; b = x[r]; d = d3;
		}
			return; 
	}

		int m = l + (r-l) / 2;
		int f = l, g = m + 1;                          		//m为中位数 
		for (int i = l; i <= r; i++)
			if (y[i].p > m) z[g++] = y[i];                //将y中数组按m左和m右分为两部分 
			else z[f++] = y[i];
		closestPair (x, z, y, l, m, a, b, d);
		float dr;
		PointX ar, br;                                     //表示右边数组中最大距离和相对应的两个点 
		closestPair (x, z, y, m+1, r, ar, br, dr);
		
		if (dr < d) {a = ar, b = br, d = dr;}

		Merge2 (z, y, l, m, r);
		
		int k = l;
		for ( int i = l; i <= r; i++)
			if (fabs(y[m].x - y[i].x) < d)
				z[k++] = y[i];
		for ( int i = l; i < k; i++)
			for (int j = i + 1; j < k && ((z[j].y- z[i].y) < d); j++)
			{
				double dp = dist(x[z[i].p], x[z[j].p]);
				if (dp < d)
				{
					d = dp; a = x[z[i].p]; b = x[z[j].p];
				}
			}
	
}

bool cpir2 (vector<PointX> x, int n, PointX &a, PointX &b, float &d)
{
	if (n < 2) exit(0);
	vector<PointX> x1(x.size());
	MergeSort1 (x, x1, 0, x.size()-1);

	vector<PointY> y(x.size ());
	vector<PointY> y1(x.size ());
	for (int i = 0; i < x.size(); i++)
		y[i].create (x[i].x, x[i].y, i);
	MergeSort2 (y, y1, 0, y.size()-1);
	vector <PointY> c(x.size());
	closestPair (x1, y1, c, 0, x.size ()-1, a, b, d);
	return true;
	
}

int main ()
{
	vector <PointX> x (8);
	for (int i = 0; i < 8; i++)
	{
		x[i].create (i+4, i+2, i);
	} 
	PointX a;
	PointX b;
	float d;

	cpir2 (x, 8, a, b, d);
	cout << a.x << " " << a.y << " " << a.ID << endl;
	cout << b.x << " " << b.y << " " << b.ID << endl;
	cout << d << endl;
	
	return 0;
}
