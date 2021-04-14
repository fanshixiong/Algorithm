#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e6+10;
ll prime[maxn], sum[maxn];
ll index1 = 0;
ll N, M;
void init(ll m){
	for(ll i = 2; i * i <= m; i++){
		while(m % i == 0){
			prime[index1] = i;
			sum[index1]++;
			m /= i;
		}
		if(sum[index1]) index1++;
	}
	if(m > 1) prime[index1] = m, sum[index1++] = 1;
}
ll getSum(ll n, ll p){
	ll sums = 0;
	while(n > 0){
		sums += n / p;
		n /= p;
	}
	return sums;
}
int main(){
	cin >> N >> M;
	init(M);
	ll ans = 1e18;
	for(ll i = 0; i < index1; i++){	
		ans = min(ans, getSum(N, prime[i]) / sum[i]);
	}
	cout << ans << endl;
	return 0;
}