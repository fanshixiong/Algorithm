#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
	long long n, k, T; 
	while(cin >> n >>k >> T){
		long long nub=1;
		long long res=1, last=1;
		for(int i=1; i<T; i++){
			nub=last+((i-1)*n+1+i*n)*n/2;
			nub%=k;
			res+=nub;
			last=nub;
		}
		cout << res << endl;
	}
	return 0;
}
