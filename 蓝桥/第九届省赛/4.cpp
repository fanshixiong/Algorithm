#include<iostream>
using namespace std;
typedef unsigned long long ull;
int x3 = 0, x5 = 0, x7 = 0;
ull num[2500];
ull min(ull n3, ull n5, ull n7){
	if (n3 < n5){
		if (n3 < n7){
			x3++;
			return n3;
		}
		else if (n3 > n7){
			x7++;
			return n7;
		}
		else{
			x3++; x7++;
			return n3;
		}
	}
	else if (n3 > n5){
		if (n5 > n7){
			x7++;
			return n7;
		}
		else if (n5 < n7){
			x5++;
			return n5;
		}
		else{
			x5++; x7++;
			return n5;
		}
	}
	else{
		if (n3 > n7){
			x7++;
			return n7;
		}
		else if (n3 < n7){
			x3++; x5++;
			return n3;
		}
		else{
			x3++; x5++; x7++;
			return n3;
		}
	}
}
int main()
{
	ull targ = 59084709587505;
	num[0] = 1;
	int i;
	for(i = 1; i < 2500; i++){
		num[i] = min(num[x3]*3, num[x5]*5, num[x7]*7);
		if (num[i] == targ)
			break;
		cout << num[i] << endl;
	}
	cout << i <<endl;
	return 0;
}
