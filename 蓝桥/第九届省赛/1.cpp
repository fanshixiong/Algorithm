#include<iostream>
#include <vector>
using namespace std;
int main()
{
    int res = 1;
    for(int i = 1; i < 20; i++)
    	res *= 2;
	cout << 2*res-1 << "/" << res << endl;
    return 0; 
}
