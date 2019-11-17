//蓝桥杯 小数高精度 

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	vector<int> res;
	map<int, int> mmp;
	res.push_back(n/m);
	n %= m;
	n *= 10;
	while (n / m != 0){
		if (mmp[n/m])
			break;
		mmp[n/m] = 1;
		res.push_back(n/m); 
		n %= m;
		n *= 10;
	} 
	cout << res[0] << ".";
	for (int i= 1; i < res.size(); i++)
		cout << res[i];
	cout << endl;
	system("PAUSE");
	return 0;
}
