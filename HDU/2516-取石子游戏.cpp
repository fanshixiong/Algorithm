#include<bits/stdc++.h>
using namespace std;

const int maxn = 55;
int f[maxn];
void init(){
	f[0]=f[1]=1;
	for(int i=2; i<=maxn; i++){
		f[i]=f[i-1]+f[i-2];
	}
}
int main(){
	init();
	int n;
	while(cin>>n && n!=0){
		bool b=0;
		for(int i=0; i<maxn; i++){
			if(n==f[i]){
				b=1;
				break;
			}
		}
		if(b)
			cout << "Second win" << endl;
		else
			cout << "First win" <<endl;
	}
	return 0;
} 
