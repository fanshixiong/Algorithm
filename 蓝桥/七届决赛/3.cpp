#include<iostream>
#include <algorithm>
#include <stdio.h>
#define N 8
using namespace std;
void f(int ta[], int da[], int k, int ho, int bu, int sc)
{
	int i,j;
	if(ho<0 || bu<0 || sc<0) return;
	if(k==N){ //cout << ho << " " << bu << endl;
		if(ho>0 || bu>0 || sc>0) return;
		for(i=0; i<N; i++){
			for(j=0; j<da[i]; j++) 
				printf("%d ", ta[i]);
		}
		printf("\n");
		return;
	}
	
	for(i=0; i<=bu; i++){
		da[k] = i;
		f(ta, da, k+1, ho-(i==0?0:1), bu-i, sc-ta[k]*i);  //Ìî¿ÕÎ»ÖÃ
	}
	
	da[k] = 0;
}

int main()
{
	int ta[] = {1,2,3,5,10,20,25,50};
	int da[N];
	f(ta, da, 0, 3, 6, 96);
	return 0;
}
