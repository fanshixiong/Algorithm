#include<iostream> 
#include <algorithm>
using namespace std;
long long catalan (int n){
	if (n == 1 || n == 2)
		return 1;
	long long res = 0;
	for (int i = 1; i <= n-1; i++)
		res += catalan(i) * catalan(n-i);
	return res;
}
int main(){
	int n; cin >> n;
	if(n <= 2){
		cout << 0 << endl;
		return 0;
	} 
	cout << catalan(n-1) << endl;
	return 0;
}
