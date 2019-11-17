#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;

unsigned int SA, SB, SC;
long long mod, n, a[20000500];
unsigned int Rand(){
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}
 int main() {
    cin>>n>>mod>>SA>>SB>>SC;
    for(int i = 1;i <= n;++i){
         a[i] = Rand() % mod + 1;
         //cout << a[i] << " ";
	}
	long long ans=0;
	if(n&1) ans=(n-1)/2*n;
	else ans=n/2*(n-1);
	long long tmp=a[n];
	for(int i=n-1; i>=1; i--){
		tmp--;
		tmp = min(tmp, a[i]);
		if(!tmp){
			ans += (i-1);
			tmp = a[i];
		} 
	}
	cout << ans << endl;
	return 0;
}
