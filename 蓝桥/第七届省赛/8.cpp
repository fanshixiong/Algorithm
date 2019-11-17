#include<iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	bool b = 0;
	for(int i = 0; i*i < n; i++){
		for (int j = i; j*j < n - i*i; j++){
			for(int k = j; k*k < n-i*i-j*j; k++){
				int y = sqrt(n-i*i-j*j-k*k);
				if (y*y+k*k+i*i+j*j == n){
					cout << i << " " << j << " "<< k << " " << y << endl;
					b = 1;
					break;
				}
			}
			if (b)
				break;
		}
		if (b)
			break;
	}
	return 0;
} 
