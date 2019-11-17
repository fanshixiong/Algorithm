//蓝桥杯 拆分平方数 

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
bool is_pf(float x){
	if (x == 0)
		return false;
	float m = (float)sqrt(x);
	return m * m == x ? 1 : 0;
} 
int main(){
	int n, m;
	cin >>n >>m;
	vector<int> res;
	if (n < 10) n = 49;
	for (int i = n; i <= m; i++){
		if (is_pf(i)){
			vector<int> a;
			int x = i;
			while (x){
				a.push_back(x%10);
				x /= 10; 
			}
			int p = 0;
			for (int j = a.size() -1; j >= 0; j--){
				p = p * 10 + a[j];
				if (is_pf(p)){
					int q = 0;
					int k = j-1;
					while (k>=0){
						q = q*10+a[k];k--;
					}
					if (q == 0) continue;
					if (is_pf(q))
						res.push_back(i);
				}
			}
			 
		}
	}
	for (int i = 0; i < res.size(); i++)
		cout << res[i] <<endl;
	system("pause");
	return 0;
}
