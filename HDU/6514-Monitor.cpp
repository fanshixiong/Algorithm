#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const int maxn = 3e7+10;
int n, m, p, q;
int a[maxn];

int main(){
	int x1, x2, y1, y2;
	while(scanf("%d%d", &n, &m) != EOF){
		scanf ("%d", &p);
		for (int i=0; i<=(n+1)*(m+1); i++)
			a[i]=0;
		//标记 
		for (int i=0; i < p; i++){
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			a[x2*(m+1) + y2]++;  //二维化一维 
			if(x1-1>=1)  
				a[(x1-1)*(m+1)+y2]--;
			if(y1-1>=1)
				a[x2*(m+1)+y1-1]--;
			if((x1-1>=1) && (y1-1>=1))
				a[(x1-1)*(m+1) + y1-1]++;
		}
		//每行从右向左做前缀和 
		for (int i=1; i<=n; i++){
			for (int j=m-1; j>=1; j--){
				a[i*(m+1)+j] += a[i*(m+1)+j+1];
			}
		}
		//每列从下到上左前缀和
		for (int i=1; i<=m; i++){
			for(int j=n-1; j>=1; j--){
				a[j*(m+1)+i] += a[(j+1)*(m+1)+i];
			}
		} 
		//计算二维前缀和
		for(int i=1; i<=n; i++){
			for (int j=1; j<=m; j++){
				a[i*(m+1)+j] = a[(i-1)*(m+1)+j] + a[i*(m+1)+j-1]-a[(i-1)*(m+1)+j-1] + (a[i*(m+1)+j]>0?1:0);
			}
		} 
		scanf("%d", &q);
		while(q--){
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			
			int ans = a[x2*(m+1)+y2] - a[(x1-1)*(m+1)+y2]-a[x2*(m+1)+y1-1]+a[(x1-1)*(m+1)+y1-1];
			if(ans == (x2-x1+1)*(y2-y1+1))
				cout << "YES" << endl;
			else 
				cout << "NO" << endl;
		}
	}
	return 0;
}
