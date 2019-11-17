#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

long long ksmqm (int a, int b, int c) // a的b次方对c取模
{
	long long res;
	a = a % c;
	while (b)
	{
		if (b & 1) res = (res * a) %c;
		b >>= 1;
		a = (a * a) %c;
	}
	return res;
 } 
 
 long long ksm (long a, long b)
 {
 	long long res;
 	while (b)
 	{
 		if (b & 1) res *= a;
 		b >>= 1;
 		a *= a;
	 }
	 return res;
 }
int main ()
{
	long long res = ksm (10, 15);
	
	return res;
}
