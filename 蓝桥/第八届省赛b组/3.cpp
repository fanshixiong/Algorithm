#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
using namespace std;
typedef unsigned long long ull;
vector<vector<double> > num(32, vector<double> (30));
int main(){
	for (int i = 0; i < 29; i++){
		for (int j = 0; j <= i; j++)
			cin >> num[i][j];
	}
	for (int i = 1; i < 30; i++){
		for (int j = 0; j <= i; j++){
			if (j == 0)
				num[i][j] = num[i][j] + num[i-1][j]/2.0;
			else
				num[i][j] = num[i][j] + num[i-1][j-1]/2.0 + num[i-1][j]/2.0;
		}
	}
	double max_x = 0.00000000;
	double min_x = 0x3f3f3f3f;
	for (int i = 0; i < 30; i++){
		max_x = max(max_x, num[29][i]);
		min_x = min(min_x, num[29][i]);
	}
	printf("%f\n%f\n", min_x, max_x);
	double m = 2086458231;
	double x = m / min_x * max_x;
	printf ("%f", x);
	return 0;
}
