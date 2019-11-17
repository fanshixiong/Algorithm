#include <iostream>
#include <vector>
using namespace std;

void MatrixChain (vector<int> &p, int n, vector<vector<int> > &m, vector<vector<int> > &s)
{                                                                      //s存放路径 即断开位置 
	for (int i = 1; i <= n; i++) m[i][i] = 0;
	for (int r = 2; r <= n; r++)                                        //r代表每次几个矩阵相乘 
		for (int i = 1; i <= n-r+1; i++) {
			int j = i + r - 1;
			m[i][j] = m[i+1][j]+p[i-1]*p[i]*p[j];                          //p存放维度信息 例如：第i个矩阵的为维度为p[i-1] * p[i]; 
			s[i][j] = i;
			for (int k = i + 1; k < j; k++){
				int t = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if (t < m[i][j]){
					m[i][j] = t;
					s[i][j] = k;
				}
			}
	}
}
void Traceback (int i, int j, vector<vector<int> > &s)
{
	if (i == j) return;
	Traceback(i, s[i][j], s);
	Traceback(s[i][j]+1, j, s);
	cout << "Multiply A" << i << "," << s[i][j];
	cout << "and A" << (s[i][j]+1) << "," << j << endl;
}
int main ()
{
	vector<int> p;
	for (int i = 0; i < 5; i++)
		p.push_back(i+4);
	vector<vector<int> > s(p.size()+1 , vector<int> (p.size()+1 ));
	vector<vector<int> > m(p.size()+1 , vector<int> (p.size()+1 ));
	MatrixChain (p, p.size(), m, s);
	Traceback (1, p.size(), s);	
	return 0;
}
