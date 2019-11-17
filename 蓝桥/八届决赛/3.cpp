#include <stdio.h>

int f3(const char* s, int begin, int end)
{
	int sum = 0;
	int i;
	for(i=begin; i<end; i++){
		if(s[i]==' ') continue;
		sum = sum * 10 + (s[i]-'0');
	}
	return sum;
}

int f2(const char* s, int begin, int end)
{
	int p = begin;
	int pro = 1;
	while(1){
		int p0 = p;
		while(p!=end && s[p]!='*') p++;
		pro *= f3(s, p0, p);  //МоїХ
		if(p==end) break; 
		p++;
	}
	printf("f2: pro=%d\n", pro);
	return pro;
}

int f(const char* s)
{
	int p = 0;
	int sum = 0;
	while(1){
		int p0 = p;
		while(s[p]!=0 && s[p]!='+') p++;
		sum += f2(s,p0,p);
		if(s[p]==0) break;
		p++;
	}
	
	return sum;
}

int main()
{
	int x = f("12+18+5*4*3+10");
	printf("%d\n", x);
	return 0;
}

