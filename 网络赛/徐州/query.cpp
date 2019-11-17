#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5+10;
int n, x, sum[maxn];

int lowbits(int x){
	return x&(-x);
}
void add(int x, int p){
	while(x<=n){
		sum[x] += p;
		x += lowbits(x);
	}
}
int getsum(int x){
	int ans = 0;
	while(x){
		ans += sum[x];
		x -= lowbits(x);
	}
	return ans;
}

vector<int> G[maxn];
vector<pair<int, int> > q[maxn];
int pos[maxn], ans[maxn]={0};
int main(){
	int m;
	memset(sum, 0, sizeof(sum));
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++){
		int x;
		scanf("%d", &x);
		pos[x] = i;
	}
	for(int i=1; i<=n; i++){
		for(int j=i*2; j<=n; j+=i){
			int x=pos[i], y=pos[j];
			if(x<y)
				swap(x, y);
			//cout << x << "  " << y << endl;
			G[x].push_back(y);
		}
	}
	//cout << "ss" << endl;
	for(int i=1; i<=m; i++){
		int l, r;
		scanf("%d%d", &l, &r);
		q[r].push_back({l, i});
	}
	for(int i=1; i<=n; i++){
		for(int j=0; j<G[i].size(); j++){
			add(G[i][j], 1);
		}
		for(int j=0; j<q[i].size(); j++){
			ans[q[i][j].second] = getsum(i)-getsum(q[i][j].first-1);
		}
	}
	for(int i=1; i<=m; i++){
		cout << ans[i] << endl;
	}
	return 0;
} 
