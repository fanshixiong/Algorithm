#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
void qsm(long long a, long long b, long long c){
	long long ans=1;
	int x=a, y=b;
	while(b){
		if(b&1) ans=(ans*a)%c;
		b>>=1;
		a=(a*a)%c;
	} 
	cout << x << "^" << y << " mod " <<c<< "=" << ans%c << endl;
}
int main(){
	std::ios::sync_with_stdio(0);
	long long x1, x2, x3;
	cin >> x1 >> x2 >>x3;
	qsm(x1, x2, x3);
	return 0;
} 
