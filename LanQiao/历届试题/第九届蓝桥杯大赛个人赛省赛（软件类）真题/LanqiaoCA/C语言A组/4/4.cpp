#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e6+10;
ll f3 = 0, f5 = 0, f7 = 0;
ll f[maxn];
ll n = 59084709587505;
int main(){
	f[0] = 1;
	ll i;
	for(i = 1; f[i-1] < n; i++){
		f[i] = min(min(f[f3]*3, f[f5]*5), f[f7]*7);
		if(f[i] / f[f3] == 3) f3++;
		if(f[i] / f[f5] == 5) f5++;
		if(f[i] / f[f7] == 7) f7++;
	}
	cout << i-1 << endl;
	return 0;
} 
