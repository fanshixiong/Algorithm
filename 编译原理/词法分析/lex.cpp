#include <bits/stdc++.h>
using namespace std;
#define MAX 32
int temp = 0;
/*
	保留字|关键字：1
	操作符|运算符：2
	界限符：3
	标识符：4
	常数：5
	无识别：6
*/
char ch = ' ';
char* keyWord[32] = { (char*)"auto",(char*)"short",(char*)"int",(char*)"long",(char*)"float",
					(char*)"double",(char*)"char",(char*)"struct",(char*)"union",(char*)"enum",
					(char*)"typedef",(char*)"const",(char*)"unsigned",(char*)"signed",
					(char*)"extern",(char*)"register",(char*)"static",(char*)"volatile",
					(char*)"void",(char*)"if",(char*)"else",(char*)"switch",(char*)"case",
					(char*)"for",(char*)"do",(char*)"while",(char*)"goto",(char*)"continue",
					(char*)"break",(char*)"default",(char*)"sizeof",(char*)"return" };
char token[20];//定义获取的字符
//判断是否是关键字
bool isKey(char* token)
{
	for (int i = 0; i < MAX; i++)
	{
		if (strcmp(token, keyWord[i]) == 0)
			return true;
	}
	return false;
}
//判断是否是字母
bool isLetter(char letter)
{
	if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
		return true;
	else
		return false;
}
//判断是否是数字
bool isDigit(char digit)
{
	if (digit >= '0' && digit <= '9')
		return true;
	else
		return false;
}
//词法分析
void analyze(FILE* fpin)
{

	while ((ch = fgetc(fpin)) != EOF) {
		if (ch == ' ' || ch == '\t' || ch == '\n') {}
		else if (isLetter(ch)) {
			char token[20] = { '\0' };
			int i = 0;
			while (isLetter(ch) || isDigit(ch)) {
				token[i] = ch;
				i++;
				ch = fgetc(fpin);
			}
			//回退一个指针
			fseek(fpin, -1L, SEEK_CUR);
			if (isKey(token)) {
				//关键字
				cout << token << "\t1" << "\t关键字" << endl;
			}
			else {
				//标识符
				cout << token << "\t4" << "\t标识符" << endl;
			}
		}
		else if (isDigit(ch) || (ch == '.'))
		{
			int i = 0;
			char token[20] = { '\0' };
			while (isDigit(ch) || (ch == '.' && isDigit(fgetc(fpin))))
			{
				if (ch == '.')
					fseek(fpin, -1L, SEEK_CUR);
				token[i] = ch;
				i++;
				ch = fgetc(fpin);
			}
			fseek(fpin, -1L, SEEK_CUR);
			//属于无符号常数
			if(temp == 0)
				cout << token << "\t5" << "\t常数(全局)" << endl;
			else
				cout << token << "\t5" << "\t常数(局部)" << endl;
		}
		else switch (ch) {
			case '+': {
				ch = fgetc(fpin);
				if (ch == '+')
					cout << "++" << "\t2" << "\t运算符" << endl;
				else {
					cout << "+" << "\t2" << "\t运算符" << endl;
					fseek(fpin, -1L, SEEK_CUR);
				}
			}
			break;
			case '-': {
				ch = fgetc(fpin);
				if (ch == '-')
					cout << "--" << "\t2" << "\t运算符" << endl;
				else {
					cout << "-" << "\t2" << "\t运算符" << endl;
					fseek(fpin, -1L, SEEK_CUR);
				}
			}
			break;
			case '*': {
				ch = fgetc(fpin);
				if (ch == '/')
					cout << "*/" << "\t2" << "\t界限符" << endl;
				else {
					cout << "*" << "\t2" << "\t运算符" << endl;
					fseek(fpin, -1L, SEEK_CUR);
				}
			}
			break;
			case '/': {
				ch = fgetc(fpin);
				if (ch == '*') {
					cout << "*/" << "\t2" << "\t界限符" << endl;
					ch = fgetc(fpin);
					string arr = "";
					string s = "";
					while (s != "*/") {
						if (ch == '*') {
							ch = fgetc(fpin);
							if (ch == '/') {
								s = "*/";
								break;
							}
						else 
							fseek(fpin, -1L, SEEK_CUR);
						}
					arr = arr + ch;
					ch = fgetc(fpin);
					}
					cout << arr << "\t6" << "\t注释内容" << endl;
					cout << s << "\t2" << "\t界限符" << endl;
				}
				else if(ch == '/') 
					cout << "//" << "\t2" << "\t界限符" << endl;
				else {
					cout << "/" << "\t2" << "\t运算符" << endl;
					fseek(fpin, -1L, SEEK_CUR);
				}
			}
			break;
			case '(':cout << ch << "\t3" << "\t界限符" << endl; break;
			case ')':cout << ch << "\t3" << "\t界限符" << endl; break;
			case '[':cout << ch << "\t3" << "\t界限符" << endl; break;
			case ']':cout << ch << "\t3" << "\t界限符" << endl; break;
			case ';':cout << ch << "\t3" << "\t界限符" << endl; break;
			case '{': {
				temp++;
				cout << ch << "\t3" << "\t界限符" << endl; break; 
			}
			case '}': {
				temp--;
				cout << ch << "\t3" << "\t界限符" << endl; break;
			}
			case ',':cout << ch << "\t3" << "\t界限符" << endl; break;
			case '"': {
				cout << ch << "\t3" << "\t界限符" << endl;
				ch = fgetc(fpin);
				string arr = "";
				while(ch != '"') {
					arr = arr + ch;
					ch = fgetc(fpin);
				}
				cout << arr << "\t6" << "\t无法识别字符" << endl;
				cout << ch << "\t3" << "\t界限符" << endl;
			}
			break;
			case '\'':cout << ch << "\t3" << "\t界限符" << endl; break;//判断单引号
			case '=': {
				ch = fgetc(fpin);
				if (ch == '=')
					cout << "==" << "\t2" << "\t运算符" << endl;
				else {
					cout << "=" << "\t2" << "\t运算符" << endl;
					fseek(fpin, -1L, SEEK_CUR);
				}
			}
			break;
			case ':': {
				ch = fgetc(fpin);
				if (ch == '=')
					cout << ":=" << "\t2" << "\t运算符" << endl;
				else {
					cout << ":" << "\t2" << "\t运算符" << endl;
					fseek(fpin, -1L, SEEK_CUR);
				}
			}
			break;
			case '>': {
				ch = fgetc(fpin);
				if (ch == '=')
					cout << ">=" << "\t2" << "\t运算符" << endl;
				else {
					cout << ">" << "\t2" << "\t运算符" << endl;
					fseek(fpin, -1L, SEEK_CUR);
				}
			}
			break;
			case '<': {
				ch = fgetc(fpin);
				string arr = "<";
				while (ch != ' ' && ch != '\t' && ch != '\n') {
					arr = arr + ch;
					ch = fgetc(fpin);
				}
				if (arr == "<=" || arr == "<") 
					cout << arr << "\t2" << "\t运算符" << endl;
				else if (arr == "<<") 
					cout << arr << "\t3" << "\t界限符" << endl;
				else if (arr[arr.length() - 1] == '>') 
					cout << arr << "\t4" << "\t头文件" << endl;
				else 
					cout << arr << "\t6" << "\t无法识别字符" << endl;		
			}
			break;
			//无识别
			default: cout << ch << "\t6" << "\t无识别符" << endl;
		}
	}
}
struct globalTableNode {	
	string id;       //变量id
	string name;  //变量名
	string type;  //变量类型
};
struct localTableNode {
	string id; //局部变量id
	string name; //局部变量名
	string type; //局部变量类型
};

vector<string> all;	//存储每一行
vector<globalTableNode> globalTable; //全局符号表
vector<localTableNode> localTable;   //局部符号表
vector<string> globalVar;	//存储全局一行
vector<string> localVar;	//存储局部
int global = 0;
string varType[9] = {"int", "double", "float", "byte", "char", "long", "void" , "#define", "string"}; //变量类型
//判断是否是数字
bool AllisNum(string str)
{
	stringstream sin(str);
	double d;
	char c;
	if (!(sin >> d))
	{
		return false;
	}
	if (sin >> c)
	{
		return false;
	}
	return true;
}
//判断选出的string中是否含有常数
bool isNum(string a) {
	string s = "";	
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != ' ' && a[i] != '\n' && a[i] != '\t' && a[i] != ';' && a[i] != '[' && a[i] != ']' && a[i] != ',')
			s = s + a[i];
		else {
			if (AllisNum(s)) {
				return true;
			}
			s = "";
		}
	}
	return false;
}
//判读是否是有变量定义且含有常数
bool isVar(string a) {
	for (int i = 0; i < 9; i++) {
		string::size_type idx;
		idx = a.find(varType[i]);
		if (idx != string::npos) {
			if (isNum(a)) {
				return true;
			}
		}	
	}
	return false;
}
//判读是否是是变量类型
bool IsVar(string a) {
	for (int i = 0; i < 9; i++) {
		string::size_type idx;
		idx = a.find(varType[i]);
		if (idx != string::npos)
			return true;		
	}
	return false;
}
//判断全局还是局部
bool isInFun(string a) {
	string::size_type idx;
	idx = a.find("{");
	if (idx != string::npos)
		return true;
	else
		return false;
}
bool isOutFun(string a) {
	string::size_type idx;
	idx = a.find("}");
	if (idx != string::npos)
		return true;
	else
		return false;
}
//选出符合条件的
void Var(string a) {
	if (isVar(a)) {
		if (global == 0)
			globalVar.push_back(a);
		else
			localVar.push_back(a);
	}
	if (isInFun(a))
		global++;
	if (isOutFun(a))
		global--;
}
void result() {
	for (int i = 0; i < all.size(); i++) {
		Var(all[i]);
	}
	for (int i = 0; i < globalVar.size(); i++) {
		int flag = 0;
		string ss = globalVar[i];
		string s = "";
		globalTableNode gl;
		for (int j = 0; j < ss.size(); j++) {
			if (ss[j] != ' ' && ss[j] != '\n' && ss[j] != '\t' && ss[j] != '=' && ss[j] != ';' && ss[j] != '[' && ss[j] != ']' && ss[j] != '(' && ss[j] != ')')
				s = s + ss[j];
			else if(s != ""){
				if (IsVar(s)) {
					gl.type = s;
					flag = 1;
				}
				if (flag == 1) {
					if (AllisNum(s)) {
						gl.id = s;
						break;
					}
					else
						gl.name = s;
				}
				s = "";
			}
		}
		if (flag == 1)
			globalTable.push_back(gl);
	}
	
	for (int i = 0; i < localVar.size(); i++) {
		int flag = 0;
		string ss = localVar[i];
		string s = "";
		localTableNode lt;
		for (int j = 0; j < ss.size(); j++) {
			if (ss[j] != ' ' && ss[j] != '\n' && ss[j] != '\t' && ss[j] != '=' && ss[j] != ';' && ss[j] != '[' && ss[j] != ']' && ss[j] != '(' && ss[j] != ')')
				s = s + ss[j];
			else if(s != ""){
				if (IsVar(s)) {
					lt.type = s;
					flag = 1;
				}
				if (flag == 1) {
					if (AllisNum(s)) {
						lt.id = s;
						break;
					}
					else
						lt.name = s;
				}
				s = "";
			}
		}
		if (flag == 1)
			localTable.push_back(lt);
	}
	cout << "全局变量：" << endl;
	cout << "变量名\t" << "\t变量值\t" << "\t变量类型" << endl;
	for (int i = 0; i < globalTable.size(); i++)
		cout << globalTable[i].name << "\t\t" << globalTable[i].id << "\t\t" << globalTable[i].type << endl;
	cout << "局部变量：" << endl;
	cout << "变量名\t" << "\t变量值\t" << "\t变量类型" << endl;
	for (int i = 0; i < localTable.size(); i++)
		cout << localTable[i].name << "\t\t" << localTable[i].id << "\t\t" << localTable[i].type << endl;
}
int main() {
	char input[30];
	FILE* fpin;
	cout << "请输入源文件名：" << endl;
	cin >> input;
	for (;;) {
		if ((fpin = fopen(input, "r")) != NULL)
			break;
		else{
			cout << "路径输入错误" << endl;
			break;
			}
	}
	cout << "****************词法分析结果********************" << endl;
	analyze(fpin);
	if(fpin != 0)
		fclose(fpin);
	fstream f(input);
	if (!f) {
		cout << "路径输入错误" << endl;
	}
	string line;
	cout << "****************符号表********************" << endl;
	while (getline(f, line))
	{
		line = line + "\n";
		all.push_back(line);
	}
	result();
	return 0;
}