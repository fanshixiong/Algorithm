// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>

#define ll long long
using namespace std;
const int maxn = 1e5*2+5;
vector<ll> a(maxn);
vector<ll> sum(maxn);
vector<ll> add(maxn);
int num1, num2;

void getup(int x) {
	sum[x] = sum[x * 2] + sum[x * 2 + 1];
}

void btree(int left, int right, int root) {
	if (left == right) {
		sum[root] = a[left];
		return;
	}
	int mid = (right - left) / 2 + left;
	btree(left, mid, root * 2);
	btree(mid + 1, right, root * 2 + 1);
	getup(root);
}
ll query(int L, int R, int left, int right, int root) {
	ll ans = 0;
	if (L <= left && right <= R) {
		return sum[root];
	}
	int mid = (right - left) / 2 + left;
	if (L < mid)
		ans += query(L, R, left, mid, root * 2);
	if(R > mid)
		ans += query(L, R, mid + 1, right, root * 2);
	return ans;
}
void Add(int L, int x, int left, int right, int root) {
	if (left == right) {
		sum[root] += x;
		return;
	}
	int mid = (right - left) / 2 + left;
	if (L <= mid)
		Add(L, x, left, mid, root * 2);
	else
		Add(L, x, mid + 1, right, root * 2 + 1);
	getup(root);
}

int main(){
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		for (int j = 1; j <= n;j++) {
			cin >> a[j];
		}
		btree(1, n, 1);
		cout << "Case" << i << ":" << endl;
		string s;
		while (cin >> s && s != "End") {
			cin >> num1 >> num2;
			if (s == "Q") {
				printf("lld\n", query(num1, num2, 1, n, 1));
			}
			else if (s == "A") {
				Add(num1, num2, 1, n, 1);
			}
			else if (s == "S") {
				Add(num1, -1 * num2, 1, n, 1);
			}
		}
	}
	return 0;
}
