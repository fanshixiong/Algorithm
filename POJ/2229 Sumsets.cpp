/*
Farmer John commanded his cows to search for different sets of numbers that sum to a given number. 
The cows use only numbers that are an integer power of 2. 
Here are the possible sets of numbers that sum to 7:

1) 1+1+1+1+1+1+1
2) 1+1+1+1+1+2
3) 1+1+1+2+2s
4) 1+1+1+4
5) 1+2+2+2
6) 1+2+4
*/

/*Due to the potential huge size of this number, 
print only last 9 digits (in base 10 representation).
 = % 1000000000
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;
const int N = 1e6+5;
const int X = 1000000000;
long long dp[N], comp[21];
long long ans=0;
int main(){
	int n;
	cin >> n;
	comp[0]=1;
	for(int i=1; i<20; i++){
		comp[i] = comp[i-1]*2;
	}
	dp[0]=1;
	/*Time Limit Exceeded 
	// 类似于完全背包，从20件物品中选取几件组成这个数。 
	for(int i=0; i<20; i++){
		for(int j=comp[i]; j<N; j++){
			dp[j] = (dp[j]+dp[j-comp[i]])%X;
		}
	}
	cout << dp[n] << endl;
	*/
	
	//递推， f[n] = f[n-1] + f[n/2], n%2==0;     f[n]=f[n-1], n%2==1;
	for(int i=1; i<=n; i++){
		if(i%2==0){
			dp[i] = (dp[i-1]+dp[i/2])%X;
		}
		else
			dp[i]=dp[i-1];
	}
	cout << dp[n] << endl;
	return 0;
} 
