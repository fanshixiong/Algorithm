#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
ll num[205];
int sum[205][2];
bool vis[205];
int n, k;
int main(){
	int sum5=0, sum2=0;
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; i++){
		sum[i][0] = sum[i][1] = 0;
 		scanf("%lld", &num[i]);
		while(!(num[i]%2)){
			sum[i][0]++;  //2
			sum2++;
			num[i]/=2;
		}
		while(!(num[i]%5)){
			sum[i][1]++;  //5
			sum5++;
			num[i]/=5;
		}
	}
	for(int i=1; i<=n-k; i++){  //ц╟ещ 
		int maxn=0, pos; 
		for(int j=1; j<=n; j++){
			if(!vis[j]){
				int tmp = min(sum2-sum[j][0], sum5-sum[j][1]);
				if(tmp > maxn){
					maxn = tmp;
					pos = j;
				}
			}
		}
		vis[pos]=1;
		sum2 -= sum[pos][0];
		sum5 -= sum[pos][1];
	}
	cout << min(sum2, sum5) << endl;
    return 0;
}
