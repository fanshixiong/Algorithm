#include<bits/stdc++.h>
using namespace std;
int a[1010][1010], cnt[1010][1010], day[1010];
int n, m, k;
int main(){
	cin>>n >> m>> k;
	for(int i=1; i<=n; i++){
		for(int j=0; j<m; j++){
			int x;
			scanf("%d", &x);
			a[i][j]=x;
			if(!cnt[j][x]){
				cnt[j][x]++;
				day[x]++;
			}
		}
	}
	for(int i=1; i<k; i++)
		printf("%d ", day[i]);
	printf("%d\n", day[k]);
	return 0;
} 
