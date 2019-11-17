#include <iostream>
#include <vector>
using namespace std;

int total = 0;
int n = 8;
vector <int> res(n);
bool is_ok ( int row)
{
	for (int j = 0; j < row; j++)
	if (res[row] == res[j] || row - res[row] == j - res[j] || row + res[row] == j + res[j])  // ·Ö±ð¶ÔÓ¦ÁÐ ×ó±ßÐ±½Ç ÓÒ±ßÐ±½Ç
		return false;
	return true;

}
void queen (int row)
{
	if (row == n)
	{
		total++;
		for (int i = 0; i < n; i++)
			cout << res[i] << " ";
		cout << endl;
	}
	else 
	{
		for (int col = 0; col < n; col++)
		{ 
			res[row] = col;
			if (is_ok(row))
				queen(row+1);
		}
	}
}

void main()
{
	queen (0);
	cout << total << endl;

}
