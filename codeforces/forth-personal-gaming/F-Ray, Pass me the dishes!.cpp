
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 50009;
ll a[maxn];
ll sum[maxn*4];

void getup(int x) {
	sum[x] = sum[x * 2] + sum[x * 2 + 1];
}

void btree(int left, int right, int root) {
	if (left == right) {
		sum[root] = a[left];
		return;
	}
	int mid = (left+right)/2;
	btree(left, mid, root * 2);
	btree(mid + 1, right, root * 2 + 1);
	getup(root);
}

ll query(int L, int R, int left, int right, int root) {
	ll ans = 0;
	if (L <= left && right <= R) {
		return sum[root];
	}
	int mid = (left+right)/2;
	if (L <= mid)
		ans += query(L, R, left, mid, root * 2);
	if(R > mid)
		ans += query(L, R, mid + 1, right, root * 2 + 1);
	return ans;
}
void Add(int L, int x, int left, int right, int root) {
	if (left == right) {
		sum[root] += x;
		return;
	}
	int mid = (left+right)>>1;
	if (L <= mid)
		Add(L, x, left, mid, root * 2);
	else
		Add(L, x, mid + 1, right, root * 2 + 1);
	getup(root);
}

int main(){
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		for (int j = 1; j <= n;j++) {
			scanf("%d", &a[j]);
		}
		btree(1, n, 1);
		int num1, num2;/*
		cout << "Case" << i << ":" << endl;
		string s;
		while (cin >> s && s != "End") {
			scanf("%d %d", &num1, &num2);
			if (s == "Query") {
				printf("%lld\n", query(num1, num2, 1, n, 1));
			}
			else if (s == "Add") {
				Add(num1, num2, 1, n, 1);
			}
			else if (s == "Sub") {
				Add(num1, -1 * num2, 1, n, 1);
			}*/
			char opt[5];
			printf("Case %d:\n",i);
			while(scanf("%s",opt)&&opt[0]!='E'){
				scanf("%d %d",&num1,&num2);
				if(opt[0]=='Q')
					printf("%lld\n",query(num1,num2,1,n,1));
				else if(opt[0]=='A')
					Add(num1,num2,1,n,1);
				else if(opt[0]=='S')
				    Add(num1,-1*num2,1,n,1);
			}
		
	}
	return 0;
}
