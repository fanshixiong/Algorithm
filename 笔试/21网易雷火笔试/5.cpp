#include<bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
#define ll long long
const int maxn = 1e5 + 10;
int a[maxn];
int n, k; 
bool check(int x){
	string s = " ";
	for(int i = 1; i <= x; i++){
		if(x % i == 0) s += to_string(i);
	}
	return s.find(to_string(k)) != s.npos;
}
int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];

	int ans = 0;
	for(int i = 0; i < n; i++){
		if(check(a[i])) ans ++;
	}
	cout << ans << endl;
	return 0;
}
/*
5 13
13 31 10 9 20
*/
