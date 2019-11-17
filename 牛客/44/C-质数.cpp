
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;
const int N = 1e6+5;
#define ll long long
ll l, r, k, cnt=0;
ll vis[N];
ll solve(ll x){
	if(x==-1) return 0;
	ll ans=0;
	for(ll i=0; i<1<<cnt; i++){
		ll p=1, f=1;
		for(ll j=0; j<cnt; j++){
			if(i>>j & 1){ //i/2^j 是基数
				p*=vis[j];
				f*=-1;
			}
		}
		ans += x/p*f;
	}
	return ans;
}
int main(){
	scanf("%lld %lld %lld", &l, &r, &k);
	if(l>r-2*k){
		cout << 0 <<endl;
		return 0;
	}
	k*=2; r-=k;
	for(ll i=2; i*i<=k; i++){
		if(!(k%i)){
			vis[cnt++]=i;
			while(!(k%i))
				k/=i;
		}
	}
	if(k!=1) vis[cnt++]=k;
	printf("%lld\n", solve(r)-solve(l-1)); //包括l 
	return 0;
} 
