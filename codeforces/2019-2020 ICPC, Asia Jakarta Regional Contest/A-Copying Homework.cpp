#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >>n;
	int a[n+1];
	int maxn=0, minn=0;
	for(int i=0; i<n; i++){
		cin >> a[i];
		if(a[maxn] < a[i])
			maxn=i;
		if(a[minn] > a[i])
			minn=i;
	}
	swap(a[maxn], a[minn]);
	for(int i=0; i<n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
} 
