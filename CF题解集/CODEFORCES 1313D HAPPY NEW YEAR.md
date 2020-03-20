# CODEFORCES 1313D HAPPY NEW YEAR



## 题目链接

https://codeforces.com/contest/1313/problem/D

## 题目大意

一共 m 个点，用 n 条线段去覆盖，问被覆盖奇数次的点最多有多少。保证一个点最多被 8 条不同的线段覆盖。

## 题目分析

注意到每个点最多被 8 条线段覆盖，猜测复杂度可能和 28 有关。考虑到如果一条线段同时覆盖 i 和 i+1 两个点，那么这条线段选不选在 i 时就可以确定。因此考虑使用 DP 解决问题。

设 F[i][S] 为已经考虑到第 i 个点，选择线段集合 S。显然已经结束的线段和还没有出现的线段不需要考虑，因此 S 可以只记录覆盖第 i 个点的几个线段。显然 i–1 已经选择的线段必选。所以可以枚举重叠部分，在考虑不重叠部分进行转移，很容易就可以解决。由于 m 很大，因此还需要对区间进行离散化，将覆盖线段相同的点分在一块儿。复杂度即可达到题目要求。

## 代码

```
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, k;

pair <int, int> a[maxn];

vector <pair <int, int> > vec;
vector <int> c[maxn];

int f[maxn][(1<<9)];
int g[(1<<9)];
int v[10];
int u[10];

int main(){
	int i, j;
	int x, y;
	int l, r;
	
	scanf("%d%d%d", &n, &m, &k);
	
	for(i=1;i<=n;i++){
		scanf("%d%d", &l, &r);
		a[i] = make_pair(l, r);
	}
	
	sort(a + 1, a + n + 1);
	
	x = 1;
	priority_queue <int> q;
	a[n + 1] = make_pair(m + 1, m + 1);
	for(i=1;i<=n+1;i++){
		while(q.size()){
			if(-q.top() < a[i].first){
				if(-q.top() >= x){
					vec.push_back(make_pair(x, -q.top()));
					x = -q.top() + 1;
				}
				q.pop();
			}else{
				break;
			}
		}
		if(x < a[i].first){
			vec.push_back(make_pair(x, a[i].first - 1));
			x = a[i].first;
		}
		q.push(-a[i].second);
	}
	
	j = 0;
	
	for(i=1;i<=n;i++){
		while(j < vec.size() and a[i].first > vec[j].first) j++;
		for(x=j;x<vec.size() and a[i].second>=vec[x].second;x++){
			c[x].push_back(i);
		}
	}
	
	int ans = 0;
	
	for(j=0;j<(1<<c[0].size());j++){
		f[0][j] = (__builtin_popcount(j) & 1) * (vec[0].second - vec[0].first + 1);
		ans = max(ans, f[0][j]);
	}
	
	for(i=1;i<vec.size();i++){
		memset(v, -1, sizeof(v));
		memset(g, 0, sizeof(g));
		int z = 0;
		for(x=0;x<c[i-1].size();x++){
			for(y=0;y<c[i].size();y++){
				if(c[i - 1][x] == c[i][y]) v[x] = y, z |= (1 << y);
			}
		}
		
		for(j=0;j<(1<<c[i-1].size());j++){
			int tmp = 0;
			for(x=0;x<c[i-1].size();x++){
				if(((j >> x) & 1) and v[x] != -1){
					tmp |= (1 << v[x]);
				}
			}
			g[tmp] = max(g[tmp], f[i - 1][j]);
		}
		
		for(j=0;j<(1<<c[i].size());j++){
			int tmp = (j & z);
			f[i][j] = max(f[i][j], g[tmp] + (__builtin_popcount(j) & 1) * (vec[i].second - vec[i].first + 1));
			ans = max(ans, f[i][j]);
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}
```

