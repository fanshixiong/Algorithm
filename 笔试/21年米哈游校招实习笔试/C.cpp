#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e3+10;

bool check(ll x){
	int odds = 0, evens = 0;
	bool flag = true;
	while(x){
		if(flag) odds += x % 10;
		else evens += x % 10;
		x /= 10;
		flag = !flag;
	}
	return odds == evens;
}
int main(){
	ll l, r;
	cin >> l >> r;
	ll ans = 0;
	for(ll i = l; i <= r; i++){
		if(check(i)) ans++;
	}
	cout << ans << endl;
	return 0;
}

/*
1
3
1 3 3
1 2 3

*/