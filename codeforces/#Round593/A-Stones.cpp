#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		int a, b, c;
		long long ans1=0, ans2=0;
		cin >> a >> b >> c;
		int a1=a, b1=b, c1=c;
		while(a1 && b1>=2){
			ans1 += 3;
			a1-=1;
			b1-=2;
		}
		while(b1 && c1>=2){
			ans1 += 3;
			b1-=1;
			c1-=2;
		}
		int a2=a, b2=b, c2=c;
		while(b2 && c2>=2){
			ans2 += 3;
			b2-=1;
			c2-=2;
		}
		while(a2 && b2>=2){
			ans2 += 3;
			a2-=1;
			b2-=2;
		}
		cout << max(ans1, ans2) << endl;
	}
	return 0;
}
