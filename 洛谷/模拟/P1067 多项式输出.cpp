// 5 
// 100 -1 1 -3 0 10
#include <iostream>
#include <cmath>
using namespace std; 
int main(){
	int n;
	cin >> n;
	for (int i = n; i >= 0; i--){
		int x; cin >> x;
		if (x){
			if (i!=n && x>0) 
				cout << "+"; 	// 100x^5
			if (abs(x)>1 || i==0) 
				cout << x; 
			if (x==-1&&i) 
				cout << "-";    // -3x^2
			if (i>1) 
				cout << "x^" << i;
			if (i==1)
				cout <<"x";		//10
		}
	}
	return 0;
}
