#include<bits/stdc++.h>
using namespace std;

int main(){
	int i,j,b=1,c=0,a=1;
	for(i=1;i<20;i++)
	{
		a = a*2;
		b += a;
	}
	printf("%d/%d\n",b,a);
	return 0;
} 
