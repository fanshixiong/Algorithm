#include<iostream>
#include <cmath>
using namespace std;

int main()
{
    int n2 = 0, n5 = 0;
    int x;
    for (int i = 0; i < 100; i++){
    	cin >> x;
    	while (1){
    		if (x % 2 == 0){
    			n2++;
    			x /= 2;
			}
			if (x % 5 == 0){
				n5++;
				x /= 5;
			}
			else
				break;
		}
	}
	cout << min(n2, n5) << endl;
    return 0; 
}
