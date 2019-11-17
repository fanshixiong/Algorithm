#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int a[11], b[11];

bool judge(ll x){
	for(int i=0; i<10; i++)
		b[i]=a[i];
	while(x){
		int t=x%10;
		if(!b[t])
			return 0;
		b[t]--;
		x/=10;
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		memset(a, 0, sizeof(a));
		for(int i=0; i<10; i++)
			cin >> a[i];
		ll ans=0;
		for(ll i=0; i<1e15; i++){
			if(judge(i))
				ans=i+1;
			else
				break;
		}
		cout << ans << endl;
	}
	return 0;
} 
