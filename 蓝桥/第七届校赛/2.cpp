#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	double res = 4;
	double ear = 1;
	for (int i = 1; i < 100; i++){
		if (ear > 0){
			ear += 2.00;
			ear = -ear;
		}
		else{
			ear = -ear;
			ear += 2.00;
		}
		res += 4.00/ear;
	}
	printf("%f", res);
	return 0;
}
