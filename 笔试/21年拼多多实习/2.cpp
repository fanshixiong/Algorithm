#include<bits/stdc++.h>
using namespace std;
bool check(int x){
	vector<int> a(10, 0);
	while(x){
		a[x % 10]++;
		x /= 10;
	}

	int cnt = 0;
	for(int i = 0; i < 10; i++){
		if(!a[i]) continue;
		if(i!= 0 && i!=1) cnt++;
	}
	return cnt <= 1;
}
int main(){
	int n; cin >> n;
	for(int i = 1; i < 200; i++){
		if(check(i * n)){
			cout << i * n << endl;
			break;
		}
	}
	return 0;
}