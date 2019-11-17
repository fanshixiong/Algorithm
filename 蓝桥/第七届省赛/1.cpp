#include<iostream>
#include <vector>

using namespace std;
int main(){
	int res = 0;
	for (int i = 10; i < 100; i++){
		int tmp1 = i % 10;
		int tmp2 = i / 10;
		int temp = tmp1*10+tmp2;
		if (i-temp == 27){
			res++;
			cout << i << " " << temp << endl;
		}
	}
	cout << res <<endl;
	return 0;
} 
