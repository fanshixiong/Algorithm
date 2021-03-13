#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, k; 
int a[maxn];
int main(){
	cin >> n >> k;
	map<int, int> p;
	for(int i = 1; i <= n; i++) cin >> a[i];
		
	for(int i = 1; i <= k; i++) p[a[i]]++;
	int maxx = 0, x;
	for(auto c : p){
		int num = c.first, cnt = c.second;
		if(maxx < cnt) maxx = cnt, x = num;
	}
	if(maxx == 1){
		for(auto c : p) { cout << c.first << endl; break; }
	}
	else cout << x << endl;
	p[a[1]]--; 

	for(int i = k+1; i <= n; i++){
		p[a[i]]++;
		maxx = 0;
		for(auto c : p){
			int num = c.first, cnt = c.second;
			if(maxx < cnt) maxx = cnt, x = num;
		}
		if(maxx == 1){
			for(auto c : p) { cout << c.first << endl; break; }
		}
		else cout << x << endl;
		//cout << a[i-k+1] << " " << a[i] << endl;
		p[a[i-k+1]]--;
	}
	return 0;
}