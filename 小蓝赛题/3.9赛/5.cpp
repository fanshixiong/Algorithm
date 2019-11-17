#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<long long> num(1000005);
int main(){
 	int n;
	cin >> n;
	if(n==1){
		cout << "LPJ" << endl;
		return 0;
	}
	bool b=0;
	
	long long res=0;
	for(int i=0; i<n; i++){
		long long x;
		cin >> x;
		if(num[x])
			b=1;
		num[x]++;
	}
	if(b)
		cout << "TY" << endl;
	else
		cout << "LPJ" << endl;
	return 0;
} 
