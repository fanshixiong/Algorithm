#include<bits/stdc++.h> 
using namespace std;
const int maxn = 1e5+10;

int a[maxn];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> v(n+1, 1);
		map<int, int> m;
		for(int i=1; i<=n; i++){
			scanf("%d", &a[i]);
			m[a[i]] = i;
		}
		for(int i=2; i<=n; i++){
			for(int j=i-1; j>0; j--){
				if(abs(m[i]-m[j])<=k){
					v[i] += v[j];
					break;
				}
			}
		}
		for(int i=1; i<=n; i++){
			if(i==1)
				printf("%d", v[i]);
			else
				printf(" %d", v[i]);
		}
		printf("\n");
	}
	return 0;
}
