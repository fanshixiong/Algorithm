#include <iostream>

using namespace std;

int Joseph (int m, int k)                  // m Ϊ ����  kΪ�ڼ���ɱ������
{
	if (m <= 0 || k <= 0)
		return -1;
	if (m == 1)
		return 0;
	else 
		return (Joseph (m-1, k) + k ) % m ;
}

void main ()
{
	cout << Joseph (41, 3)+1 <<endl;

}