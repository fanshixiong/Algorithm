#include <iostream>
#include <vector>
using namespace std;
int main(){
	for (int a = 1; a < 32; a++)
		for (int b = a ; b < 32; b++)
			for (int c = b; c < 32; c++){
				if (a*a + b*b + c*c == 1000){
					cout << a << " " <<b << " " << c << endl;
				}
			}
		
	return 0;
}
