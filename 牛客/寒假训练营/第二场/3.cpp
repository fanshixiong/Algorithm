#include <iostream>
using namespace std;
int main(){
	char* str1="four";
	char* str2=new char[4];    //not enough space
	char* str3=str2;
	cout<<str2<<endl;    //UMR
	strcpy(str2,str1);    //ABW
	cout<<str2<<endl;  //ABR
	delete str2;
	str2[0]+=2;    //FMR and FMW
	delete str3;    //FFM
	return 0;
}