#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int maxn = 1e5+10;
ll n, m, q;
ll num[maxn];

map<ll, ll> mp;  

ll MOD(ll a, ll mi){ //扩展欧几里得结果 
	return a >= mi ? (a % (mi) + mi) : a;
}  
ll qpow(ll x,ll n,ll mod)  
{  
    ll res=1;  
    while(n)  
    {  
        if (n&1) res=MOD(res*x,mod),n--;  
        x=MOD(x*x,mod); n>>=1;  
    }  
    return res;  
}  
  
ll phi(ll k)  
{  
    ll i,s=k,x=k;  
    if (mp.count(k)) return mp[x];                  //记忆化存储  
    for(i = 2;i * i <= k; i++)  
    {  
        if(k % i == 0) s = s / i * (i - 1);  
        while(k % i == 0) k /= i;  
    }  
    if(k > 1) s = s / k * (k - 1);  
    mp[x]=s; return s;  
}



/*
ll phi(ll n){
	ll ans = n;
	for (int i=2; i*i<=n; i++){
		if(n % i == 0){
			ans -= ans/i; //等价于通项，把n乘进去 
			while(n%i == 0)  //确保下一个i是n的素因数 
				n /= i;
		}
	}
	if(n > 1) ans -= ans / n; //最后可能还剩下一个素因数没有除 
	return ans;
}


ll qsm(ll a, ll b, ll c){ //快速幂 
	if(!c)
		return 0;
	ll ans = 1, base = a;
	while(b != 0){
		if(b&1)
			ans = MOD(ans*base, c);
		base = MOD(base * base, c); //回溯时也得扩展欧几里得 
		b >>= 1;
	}
	return MOD(ans, c); //扩展欧几里得 
}
*/
ll solve(ll l, ll r, ll mi){
	if(l == r || mi == 1) 
		return MOD(num[l], mi);
	return qpow(num[l], solve(l+1, r, phi(mi)), mi);
}
int main(){
	scanf("%lld%lld", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%lld", &num[i]);
	}
	cin >> q;
	while(q--){
		ll l, r;
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", solve(l, r, m)%m);
	}
	return 0;
} 
