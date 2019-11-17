#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(){
	double beg = 2.0000000;
	double end = 3.0000000;
	while (beg < end){
		double x = (end - beg) / 2 + beg;
		if (fabs(10.0-pow(x, x)) <= 0.000001){
			printf("%.8lf", x);
			break;
		}
		else if(pow(x, x) > 10){
			end = x - 0.00000001;
		}
		else if (pow(x,x) < 10){
			beg = x + 0.00000001;
		}
	}
	return 0;
}
