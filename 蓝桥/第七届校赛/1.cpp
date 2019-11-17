#include <stdio.h> 
#include <string.h>
inline max(int a, int b)
{
	return a>b?a:b;
}

int f(char* x, char* y)
{
	if(strlen(x)==0) return 0;
	if(strlen(y)==0) return 0;
	
	if(*x == *y) return f(x+1, y+1) + 1;
	
	return max( f(x, y+1), f(x+1, y));
}

int main()
{
	printf("%d\n", f("ac","abcd")); //2
	printf("%d\n", f("acebbcde1133","xya33bc11de")); //5
	return 0;
}
