#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;
const int mod = 1e9+7;
ll qsm(ll a, ll b){
	ll res = 1;
	while(b){
		if(b&1) res = (res * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	return res;
} 
int main(){
	string s;
	while(cin >> s){
		ll n = 0;
		for(int i=0; i<s.size(); i++){
			n = n*10 + (s[i] - '0');
			n %= (mod - 1);
		}
		n += mod - 1;
		ll res = qsm(2, n-1);
		ll ans = (res % mod * (res + 1) % mod) % mod;
		cout << ans << endl;
	}
	return 0;
} 
