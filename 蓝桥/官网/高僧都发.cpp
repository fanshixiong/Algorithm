// Nim ���ģ����
// ���ű���Dev������ ������ 12���� 13-18��   ���ڲ�֪����Ŀ�����ֵĶ�ȡDev���ܺܺõض�ȡ������n++д��ѭ�����ѭ���������� 

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
