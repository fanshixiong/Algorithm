// Nim 博弈：异或
// 蓝桥杯与Dev不兼容 如下文 12行与 13-18行   对于不知道数目的数字的读取Dev不能很好地读取，而且n++写在循环里和循环外有区别； 

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main(){
	int N;
	int x, n=0;
	vector<int> num(101);
	//while (scanf("%d", &num[n++]) != EOF); 
	while (scanf("%d", &num[n]) != EOF) n++;
	//while (cin >> x){
	//	if(x == 0)
	//		break;
	//	num[n++]=x;
	//	cout << num[n-1] << endl;
	//}
	//cout << n <<endl;
	vector<int> sub(101);
	int res = 0;
	for (int i = 1; i < n; i++){
		sub[i-1] = num[i]-num[i-1]-1;
		//cout << sub[i-1] << " ";
	}
	for (int i = 0; i < n-1; i+=2)
		res ^= sub[i];
	if (res == 0){
		cout << -1 <<endl;
		return 0;
	}
	for (int i = 0; i < n-1; i++){
		for (int j = 1; num[i]+j < num[i+1]; j++){
			sub[i] -=j;
			if(i != 0)
				sub[i-1]+=j;
			int ans = 0;
			for (int m=0; m<n-1; m+=2)
				ans ^= sub[m];
			if (ans == 0){
				cout << num[i] << " " << num[i]+j;
				break;
			}
			sub[i] +=j;
			if(i != 0)
				sub[i-1]-=j;
			
		}
	}
	return 0;
}
