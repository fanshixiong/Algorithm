#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll a, b, m;

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

ll MOD(ll a, ll mi){ //扩展欧几里得结果 
	return a >= mi ? a % (mi) + mi : a;
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

ll f(ll b, ll mi){
	if(mi == 1){
		return MOD(a, 1);  //模数为一时停止计算，因为之后的结果都一样 
	}
	if(b == 1)
		return MOD(a, mi); //最后一层的情况 
	return qsm(a, f(b-1, phi(mi)), mi); //递归调用 
}

void solve(){
	scanf("%lld%lld%lld", &a, &b, &m);
	if(b == 0 || a == 1 || m == 1){ //特殊情况直接输出 
		printf("%lld\n", 1%m);
		return;
	}
	if(b == 1){
		printf("%lld\n", a%m);
		return;
	}
	ll ans = f(b, m)%m;
	printf("%lld\n", ans);
}
int main(){
	int t;
	cin >>t;
	while(t--){
		solve();
	}
	return 0;
} 
