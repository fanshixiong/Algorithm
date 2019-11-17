#include <iostream>
#include <vector>  
using namespace std;  //此算法求 m个子段最大和 
int MaxSum (int m, int n, vector<int> &a )
{
	if (n <m || m < 1) return 0;
	vector<vector<int> > b(m+1, vector<int> (n+1, 0));   //b[m][j] 代表长度为m的最大子数组和 
	for(int i = 1; i < m+1; i++)
		for (int j = i; j < n-m+i; j++)                        //为什么是n-m+i 而不是n  n对不对？   节省时间，因为算b[i][j]时只用到了b[i-1][j-1]所以不用把整个列表都求出 
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

int MaxSum1(int m, int n, vector<int> &num){      //观察上述算法的表格可以发现 每次求b[i][j]时 只用了第i行和第i-1行，所以只需记录第i-1行即可 
	if (n < m || m < 1) return 0;
	vector<int> b(n+1, 0);
	vector<int> c(n+1);
	for (int i = 1; i < m; i++){
		b[i] = b[i-1] +  num[i];
		c[i-1] = b[i];                           //记录第i-1行 
		int max = b[i];                          //最大值 
		cout << i << " " << b[i] << endl;
		for(int j = i+1; j <= i + n - m; j++){
			b[j] = b[j-1] > c[j-1] ? b[j-1] + num[j] : c[j-1] +num[j];
			c[j-1] = max;
			cout << j << " " << b[j] << endl;
			if (max < b[j]) max = b[j];
		}
		c[i+n-m] = max;                       //更新第i-1行最后一个的元素为最大值，下次比较时用 
		cout << i << "i+n-m"<<i+n-m <<" " << c[i+n-m] << endl;
	}
	int sum = 0;                             //一维同理 
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
