/*
**@@author:ForeverؼCIL :algorithm 
**author:moye�������� :build circle
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int> per_a(50005), per_b(50005);
vector<int> circle(50005);
int n;
void init(){
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> per_a[i] >> per_b[i];
	circle[1]=1;
	circle[2]=per_a[1];
	for(int i=1; i<=n; i++){
		if((per_a[per_b[i]]!=i && per_b[per_b[i]]!=i) || (per_a[per_a[i]]!=i && per_b[per_a[i]]!=i)){
			//��Ϊ һ�����Աߵ��Ա߲������Լ��� ���ж�һ�� 
			cout << -1 << endl;
			exit(0);
		}
		if(circle[i-1] == per_a[circle[i]]) //�ж�i-1λ����վ������ߣ�a�����˻����ұߣ�b�����ˡ� 
			circle[i+1]=per_b[circle[i]];
		else
			circle[i+1]=per_a[circle[i]];
	}
	//for(int i=1; i<=n; i++)
	//	cout << circle[i] << " "; 
}
void sulotion(){ //���ֵ 
	vector<int> sul1(50005), sul2(50005);
	//�ֱ������������Ĳ�ֵ    
	for(int i=1; i<=n; i++){
		sul1[(circle[i]-i+n)%n]++;
		sul2[(circle[n-i+1]-i+n)%n]++;
	}
	int ans=0;
	for(int i=0; i<=n-1; i++){  //ע����0��n-1����0 
		ans = max(ans, max(sul1[i], sul2[i]));
	}
	cout << n-ans <<endl;
} 
int main(){
	init();
	sulotion();
	return 0;
} 
