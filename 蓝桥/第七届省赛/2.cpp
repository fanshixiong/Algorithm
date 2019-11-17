#include<iostream>
#include <vector>
using namespace std;
int main(){
	for (int i = 1; i < 250; i++){
		int res = 0;
		for (int j = i; j < 250; j++){
			res += j;
			if (res == 236){
				cout << i << endl;
				break; 
			}
		}
	}
	return 0;
} 
