#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll a, b, m;

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

ll MOD(ll a, ll mi){ //��չŷ����ý�� 
	return a >= mi ? a % (mi) + mi : a;
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

ll f(ll b, ll mi){
	if(mi == 1){
		return MOD(a, 1);  //ģ��Ϊһʱֹͣ���㣬��Ϊ֮��Ľ����һ�� 
	}
	if(b == 1)
		return MOD(a, mi); //���һ������ 
	return qsm(a, f(b-1, phi(mi)), mi); //�ݹ���� 
}

void solve(){
	scanf("%lld%lld%lld", &a, &b, &m);
	if(b == 0 || a == 1 || m == 1){ //�������ֱ����� 
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
