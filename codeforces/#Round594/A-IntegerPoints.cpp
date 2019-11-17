#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin >> t;

	while(t--){	
		int n, m;
		cin >> n;
		ll odd=0, even=0;
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			if(x&1)
				odd++;
			else
				even++;
		}
		cin >> m;
		ll ans=0;
		for(int i=0; i<m; i++){
			int x;
			cin >> x;
			if(x&1)
				ans += odd;
			else
				ans += even;
		}
		cout<< ans<<endl;
	}
	return 0;
}
