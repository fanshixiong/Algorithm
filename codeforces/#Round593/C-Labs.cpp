#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	ios::sync_with_stdio(0);
	cin >> n;
	int a[303][303];
	a[0][0]=1;
	for(int i=2; i<n; i+=2){
		a[0][i] = a[0][i-2]+2*n;
	}
	for(int i=1; i<n; i+=2){
		a[0][i] = a[0][i-1]+2*n-1;
	}
	for(int i=0; i<n; i++)
		cout << a[0][i] << " ";
	cout << endl;
	for(int i=1; i<n; i++){
		int b=1;
		for(int j=0; j<n; j++){
			a[i][j] = a[i-1][j] + b;
			b*=-1;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
