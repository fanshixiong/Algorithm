// 思路： 考虑m的取值条件 

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<sstream>
using namespace std;
int INF = 0x3f3f3f3f;
vector<int> pow2, pow1; //pow2[i] 代表第i个圆盘从A移到C的步数            pow1[i]代表代号为i的圆盘的权值 
void Init(int n){
	pow2[0] = 1; 
	for (int i = 1; i <= n; i++){
		pow2[i] = pow2[i-1] << 1;
		pow1[i] = pow2[i] >> 1;
	}
}
void Hanoi(vector<int> &a, vector<int> &b, vector<int> &c, int n, int k){
	if (n == 0) return;
	if (k >= pow2[n-1]) {
		c.push_back(pow1[n]);
		k -= pow2[n-1];
		Hanoi (b, a, c, n-1, k);
	}
	else{
		a.push_back(pow1[n]);
		Hanoi (a, c, b, n-1, k); 
	}
} 
int main (){

	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<int> a, b, c;
	pow2.resize(n+1);
	pow1.resize(n+1);  
	Init(n);
	Hanoi(a, b, c, n, k);
	int res1 = 0, res2 = 0, res3 = 0;
	for (int i = 0; i <= n; i++){
		if (i < a.size())
		res1 += a[i];
		if (i < b.size())
		res2 += b[i];
		if (i < c.size())
		res3 += c[i];
	}
	cout << res1 << " " << res2 << " " << res3 << endl;
	return 0;
}
