#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	long long t; cin >> t;
	while(t--){
		long long x, y; cin >> x >> y;
		
		if(x < y){
			long long tp=x;  x=y; y=tp;
		}
		if(x/y > 1){
			cout << "Stan wins" << endl;
			continue;
		}
		int b=1;
		while(x/y==1 && x%y!=0){
			x%=y;
			if(x < y){
				long long tp=x;  x=y; y=tp;
			}
			b=-b;
		}
		if(b==1)
			cout << "Stan wins" << endl;
		else
			cout << "Ollie wins" << endl;
			
	}
	return 0;	
} 
