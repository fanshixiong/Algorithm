/*

S(i)代表共有i个约数的最小的数，
求 S(1)+S(2)+S(3)+…+S(60)
 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int num[4000005];
void prime(){ //求约数 
	for(int i=1; i<=4000000; i++){
		for(int j=i; j<=4000000; j+=i){
			num[j]++;
		}
	}
}
int main(){
	prime();
	int k=1;
	long long ans=0;
	for(int m=1; m<=60; m++){
		bool b=0;
		for(int i=1; i<4000000; i++){
			if(num[i]==m){
				cout << m << " " << i <<endl;
				ans += i;
				b=1;
			}
			if(b)
				break;
		}
	}
	cout << ans << endl;
	return 0;
} 
