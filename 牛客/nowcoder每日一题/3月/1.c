#include<stdio.h>
#include <stdint.h>
int main(){
	uint32_t a = 100;
	while(a > 0){
		 --a;
	}
	printf("%d\n", a);
    return 0;
}