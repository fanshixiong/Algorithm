#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int maxn = 1e5+10;
ll n, m, q;
ll num[maxn];

map<ll, ll> mp;  

ll MOD(ll a, ll mi){ //��չŷ����ý�� 
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
    if (mp.count(k)) return mp[x];                  //���仯�洢  
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
			ans -= ans/i; //�ȼ���ͨ���n�˽�ȥ 
			while(n%i == 0)  //ȷ����һ��i��n�������� 
				n /= i;
		}
	}
	if(n > 1) ans -= ans / n; //�����ܻ�ʣ��һ��������û�г� 
	return ans;
}


ll qsm(ll a, ll b, ll c){ //������ 
	if(!c)
		return 0;
	ll ans = 1, base = a;
	while(b != 0){
		if(b&1)
			ans = MOD(ans*base, c);
		base = MOD(base * base, c); //����ʱҲ����չŷ����� 
		b >>= 1;
	}
	return MOD(ans, c); //��չŷ����� 
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
