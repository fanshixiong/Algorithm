#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;
int a[maxn];
int main(){
	
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	sort(a, a+n);
	for(int i = n-1; i>=0; i--){
		for(int j = i-1; j>=0; j--){
			for(int p = j-1; p>=0; p--){
				int sum = a[i] + a[j] + a[p];
				if(sum % k == 0){
					cout << a[i] << " " << a[j] << " " << a[p] << endl;
 					cout << sum << endl;
					return 0;
				}
			}
		}
	}
	
	return 0;
} 
