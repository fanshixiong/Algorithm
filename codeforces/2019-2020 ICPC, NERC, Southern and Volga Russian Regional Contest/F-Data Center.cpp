#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int ans=0x3f3f3f;
	for(int i=1; i<=n; i++){
		int tp = n/i;
		if(tp*i != n)
			continue;
		ans = min(2*(tp+i), ans);
	}
	cout << ans << endl;
	return 0;
}
