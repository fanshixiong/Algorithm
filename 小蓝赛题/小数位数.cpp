#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int main(){
	long long m,n,k;
	cin >> m >> n >> k;
	m = m % n;
	while (k-10>0){                 //ÿ��ȡʮλ�����ٱƽ�С���㣬ȷ��k��λ�� 
		m*=1e10;
		m%=n;
		k-=10;
	}
	for(int i = 0; i < k + 2; i++){
		m*=10;
		if (i >= k-1)
			cout << m/n;
		m%=n;
	} 
	return 0;
}
