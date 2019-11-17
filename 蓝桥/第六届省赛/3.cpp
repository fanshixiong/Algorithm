#include <iostream>
#include <vector>
using namespace std;
int main(){
	for (int a = 31; a < 102; a++){
		if ( a* a == 4761)
			cout << a <<" "<<a *a << " " << a*a*a << endl;
	}
		
	return 0;
}
