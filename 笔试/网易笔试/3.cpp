#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll qsm(ll x){
	ll ans = 1, b = 3;
	while(b){
		if(b & 1) ans = ans * x;
		x = x * x;
		b >>= 1;
	}
	return ans;
}
int main(){
	ll beg, end;
	cin >> beg >> end;

	int x = 1;
	while(qsm(x) < beg) x++;

	vector<ll> v;
	while(qsm(x) <= end){
		v.push_back(qsm(x));
		x++;
	} 
	if(v.size() == 0) cout << "[]" << endl;
	else{
		cout << "[";
 		for(int i = 0; i < (int)v.size()-1; i++){
 			cout << v[i] << ",";
		}
		cout << v.back() << "]" << endl;
	}
	return 0;
}