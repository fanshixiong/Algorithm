#include <iostream>
#include <vector>  
using namespace std;  //���㷨�� m���Ӷ����� 
int MaxSum (int m, int n, vector<int> &a )
{
	if (n <m || m < 1) return 0;
	vector<vector<int> > b(m+1, vector<int> (n+1, 0));   //b[m][j] ������Ϊm������������ 
	for(int i = 1; i < m+1; i++)
		for (int j = i; j < n-m+i; j++)                        //Ϊʲô��n-m+i ������n  n�Բ��ԣ�   ��ʡʱ�䣬��Ϊ��b[i][j]ʱֻ�õ���b[i-1][j-1]���Բ��ð������б���� 
			if (j > i)
			{
				b[i][j] = b[i][j-1] + a[j];
				cout << i << "  " << j << " " << b[i][j] << endl;
				for (int k = i - 1; k < j; k++)
					if (b[i][j] < b[i-1][k] + a[j])
					{
						b[i][j] = b[i-1][k] + a[j];
						cout << i << "  " << j << " " << b[i][j] << endl;
					}

			}
			else{
				b[i][j] = b[i-1][j-1] + a[j];
				cout << i << "  " << j << " " << b[i][j] << endl;
			}
			int sum = 0;
			for (int j = m; j <= n; j++)
				if (sum < b[m][j])
				{
					sum = b[m][j];
					cout << j << " "  << b[m][j] << endl;
				}
	return sum;
}

int MaxSum1(int m, int n, vector<int> &num){      //�۲������㷨�ı����Է��� ÿ����b[i][j]ʱ ֻ���˵�i�к͵�i-1�У�����ֻ���¼��i-1�м��� 
	if (n < m || m < 1) return 0;
	vector<int> b(n+1, 0);
	vector<int> c(n+1);
	for (int i = 1; i < m; i++){
		b[i] = b[i-1] +  num[i];
		c[i-1] = b[i];                           //��¼��i-1�� 
		int max = b[i];                          //���ֵ 
		cout << i << " " << b[i] << endl;
		for(int j = i+1; j <= i + n - m; j++){
			b[j] = b[j-1] > c[j-1] ? b[j-1] + num[j] : c[j-1] +num[j];
			c[j-1] = max;
			cout << j << " " << b[j] << endl;
			if (max < b[j]) max = b[j];
		}
		c[i+n-m] = max;                       //���µ�i-1�����һ����Ԫ��Ϊ���ֵ���´αȽ�ʱ�� 
		cout << i << "i+n-m"<<i+n-m <<" " << c[i+n-m] << endl;
	}
	int sum = 0;                             //һάͬ�� 
	for (int j = m; j <= n; j++)
		if (sum < b[j]) sum = b[j];
	return sum;	
 } 

int main()
{
	vector<int> num;
	for (int i = 0; i < 5; i++)
		num.push_back(i+3);
	num.push_back(-5);
	num.push_back(-3);
	for(int i = 0; i < 3; i++)
		num.push_back(i-2);

	cout << MaxSum1(5, num.size()-1, num) << endl;    
	return 0;
}
