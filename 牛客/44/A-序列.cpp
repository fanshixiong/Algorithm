#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n, m;
	cin >> n >> m;
	vector<int> L(m+1), R(m+1); 
 	for(int i=1; i<=n; i++){
 		int x;
 		cin >> x;
 		if(L[x]==0)
 			L[x]=i;
 		R[x]=max(R[x], i);
	}
	for(int i=m; i>=1; i--){
		if(!R[i]){
			R[i]=R[i+1];
			L[i]=L[i+1];
		}
	}
	for(int i=1; i<=m; i++)
		cout << L[i] << " " <<R[i] <<endl;
    return 0;
}
