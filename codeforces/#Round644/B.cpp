#include<bits/stdc++.h>
using namespace std;
bool AllisNum(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		int tmp = (int)str[i];
		if (tmp >= 48 && tmp <= 57)
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}
bool isNum(string a) {
	string s = "";	
	//cout << a << endl;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != ' ' && a[i] != '\n' && a[i] != '\t' && a[i] != ';' && a[i] != '[' && a[i] != ']')
			s = s + a[i];
		else {
			if (AllisNum(s)) {
			//	cout << s << endl;
				return true;
			}
			s = "";
		}
	}
	return false;
}
//判读是否是有变量定义且含有常数
string varType[7] = {"int", "double", "float", "byte", "char", "long", "void"}; //变量类型

bool isVar(string a) {
	//cout << a << endl;
	for (int i = 0; i < 7; i++) {
		string::size_type idx;
		idx = a.find(varType[i]);
		if (idx != string::npos) {
			if (isNum(a)) {
				cout << a << endl;
				return true;
			}
		}	
	}
	return false;
}

int main(){
    string a = "int a = 12;";
    cout << isVar(a) << endl;
    return 0;
}