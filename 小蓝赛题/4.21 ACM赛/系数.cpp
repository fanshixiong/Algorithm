#include<iostream>
#include<algorithm>
using namespace std;
long long C[1005][1005]={1}; 
long long ksm(long long a, long long b, long long c){
	long long ans=1;
	while(b){
		if(b&1) ans=(ans*a)%c;
		b>>=1;
		a=(a*a)%c;
	}
	return ans;
}
int main(){
	long long a, b, k, m, n;
	cin >> a >> b >> k >> n >> m;
	for(int i=0; i<=k; i++){
		C[i][0]=1;
		for(int j=1; j<=i; j++){
			C[i][j]=(C[i-1][j-1] + C[i-1][j]) % 10007;
		}
	}
	cout << (C[k][n] * ksm(a, n, 10007) * ksm(b, m, 10007) % 10007 )<< endl;
	return 0;
} 
