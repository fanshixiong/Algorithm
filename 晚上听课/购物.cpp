// 2018.12.13
//������ ������  ���к��ʾ�

//���У���һ�죬��ţȥ�����������������и�����ֵ����ԣ�����һ�������ļ۸�һ��Ҫ����һ���ĵ͡�
//���ڸ��������ﶫ���ļ۸�������ţ���ѡ����ܹ������Ķ����أ����������ţ�����ķ������� 

//��������һ��Ϊ��ݼ������е����⣬�򵥵�dp��f[i] = max(f[j]) + 1, ( 1 <= j < i < n )
//�ؼ��ڵڶ��ʵĴ��� : ����p[i]��������е����һ��Ԫ�أ���max(f[i])��������ķ���������״̬ת�Ʒ��̣�p[i] =  max(p[j)+p[i] (j����f[j] = f[i]-1)

#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

int main(){
	freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++){
		cin >> nums[i];
	}
	vector<int> f(n, 1), p(n, 1);
	for (int i = 0; i < n; i++){
		for (int j = i-1; j >= 0; j--){
			/*if (nums[i] == nums[j]){
				p[i] = 0;
			}*/
			if(nums[i] < nums[j]){
				if (f[i] == f[j] + 1)
					p[i] += p[j]; 
				else if(f[i] < f[j] + 1){
					f[i] = f[j] + 1;
					p[i] = p[j];
				}
			}
		}
	}
	int max = *max_element(f.begin(), f.end());
	int res = 0;
	for (int i = 0; i < n; i++){
		if (f[i] == max)
			res += p[i];
	}
	cout << max << " " <<res<<endl;
	return 0;
}
