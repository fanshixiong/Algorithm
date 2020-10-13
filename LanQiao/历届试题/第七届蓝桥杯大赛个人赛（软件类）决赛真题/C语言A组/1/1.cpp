#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int main(){
	int i, j, b=1, c=0, a=1;
	for(i=1; i<20; i++){
		a = a*2;
		b += a;
	}
	int t = gcd(b, a);
	while(t != 1){
		b /= t;
		a /= t;
		t = gcd(b, a);
	}
	printf("%d/%d\n",b,a);
	return 0;
} 
