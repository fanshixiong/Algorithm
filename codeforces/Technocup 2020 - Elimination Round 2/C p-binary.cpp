#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, p;

int judge(ll x){
	ll cnt=0;
	while(x){
		if(x%2)
			cnt++;
		x/=2;
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(0);
	cin >> n >> p;
	if(n==0){
		cout << 0 << endl;
		return 0;
	}
	for(int i=1; i<=64; i++){
		n-=p;
		if(n<=0){
			cout << -1 << endl;
			return 0;
		}
		if(judge(n) <= i && n >= i){
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
