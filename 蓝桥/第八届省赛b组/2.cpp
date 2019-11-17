#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int prime[900000];
bool Prime(int x){
	int n = sqrt(x);
	for (int i = 2; i <= n; i++){
		if(x % i == 0)
			return false;
	}
	return true;
}
int main(){
	for (int i = 2; i < 900000; i++){
		if (Prime(i))
			prime[i]=1;
	}
	for (int len = 10; len < 1000; len++){
		for (int i = 2; i < 900000; i++){
			bool b = 1;
			for (int j = 0; j < 10; j++){
				if (!prime[i+j*len])
					b = 0;
			}
			//cout << len << endl; 
			if (b){
				cout << len << endl;
				return 0;
			}
		}
	}
	return 0;
} 
