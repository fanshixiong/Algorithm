#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long> nums(1000000);
long long gcd(long long a, long long b){
	return b==0?a:gcd(b, a%b);
}
int main(){
	int m, n;
	cin >> m >> n;
	long long p=gcd(m, n);
	nums[0]=1;nums[1]=1;
	for(long long i=2; i<=p; i++)
		nums[i]=(nums[i-1]+nums[i-2])%100000000;
	cout << nums[p-1];
	return 0;
} 
