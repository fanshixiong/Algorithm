#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
int n, m;
int a[maxn], q[maxn], ans[maxn];
int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	ans[n-1]=-1;
	int tail=0;
	q[++tail]=n-1;
	for(int i=n-2; i>=0; i--){
		int tp = a[i]+m;
		if(a[q[tail]] < tp){
			ans[i]=-1;
			if(a[q[tail]] < a[i]) q[++tail]=i;
		}
		else{
			int l=1, r=tail;
			while(l<r){
				int mid = (l+r)>>1;
				if(a[q[mid]] >= tp) r=mid;
				else l= mid+1;
			}
			ans[i] = q[l]-i-1;
		}
	}
	for(int i=0; i<n-1; i++)
		printf("%d ", ans[i]);
	printf("-1\n");
	return 0;
}
