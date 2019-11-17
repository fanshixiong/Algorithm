#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int a[100010];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	sort(a, a+n);
	ll x=0, y=0;
	int left=0, right=n-1;
	while(left<right){
		x += a[left];
		y += a[right];
		left++;
		right--;
	} 
	if(n%2){
		y+=a[right];
	}
	ll ans = x*x+y*y;
	cout << ans << endl;
	return 0;
}
