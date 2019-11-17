#include <iostream>
using namespace std;
int gcd(int a, int b){
	return a % b ? gcd(b, a%b) : b;
}
int lcm(int a, int b){
	return a*b/gcd(a, b);
}
int main(){
	int x, y, z;
	cin >> x >> y >> z;
	cout << lcm(x, lcm(y,z)) << endl;
	return 0;
}
