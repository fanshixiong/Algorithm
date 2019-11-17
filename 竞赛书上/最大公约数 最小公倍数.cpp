/*最大公约数  最小公倍数 
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;
int GCD(int a, int b){
	return !b ? a : GCD(b, a%b);
}
int main(){
	freopen("in.txt", "r", stdin);
	int m, n, a;
	cin >> m >>n >> a;
	cout << GCD(m, a) << endl;
	cout << m/GCD(m, a)*a<<endl; 
	return 0;
} 
