#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int num[1000010];
int n, m;
void lucky(int k){
	int t=k;
	for(int i=k;i<2*m; i++){
		if(((i+1)%num[k]) != 0)
			num[t++]=num[i];
	}
}
int main(){
	cin >> n >> m;
	for(int i=0; i<500010; i++){
		num[i]=2*i+1;
	}
	int j=1, ans=0;
	while(num[j]<n){
		lucky(j);
		j++;
	}
	while(num[j]<m){
		lucky(j);
		j++;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
