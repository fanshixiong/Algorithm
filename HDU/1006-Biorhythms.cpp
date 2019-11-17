#include <iostream>
#include<cstring>

using namespace std;

int a[4], m[4];
void extend_Euclid(int a, int b, int &x, int &y){
	if(b==0){
		x=1;
		y=0;
		return;
	}
	extend_Euclid(b, a%b, x, y);
	int tp = x;
	x = y;
	y = tp-(a/b)*y;
}
int CRT(int n){
	int M=1, ans=0;
	for(int i=1; i<=n; i++){
		M *= m[i];
	}
	for(int i=1; i<=n; i++){
		int x, y;
		int Mi=M/m[i];
		extend_Euclid(Mi, m[i], x, y);
		ans = (ans + Mi*x*a[i])%M;
	}
	if(ans<0) ans += M;
	return ans;
}
int main(){
	int p, d, t=1, e, i;
	while(cin >> p >> e >>i >> d){
		if(p==-1 && e==-1 && i==-1 && d==-1)
			break;
		a[1]=p; a[2]=e; a[3]=i;
		m[1]=23; m[2]=28; m[3]=33;
		int ans=CRT(3);
		if (ans <= d)
			ans += 21252;
		cout << "Case " << t++ << ": the next triple peak occurs in "<< ans-d << " days."<<endl;
	}
	return 0;
}
