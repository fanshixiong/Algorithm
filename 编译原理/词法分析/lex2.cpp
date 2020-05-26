#include<bits/stdc++.h> 
using namespace std; 

#define MAX 16
bool flg = false;

string key[MAX]={"begin", "end", "if", "then", "else", "while", "write", "do", "call", 
				"const", "char", "until", "procedure", "repeat", "int"}; 

bool Iskey(string c){         //关键字判断  
	for(int i = 0; i < MAX; i++) {  
		if(key[i].compare(c) == 0)  return true; 
	}
	return false; 
} 
 
bool IsLetter(char c) {        //判断是否为字母
	if(((c <= 'z') && (c >= 'a')) || ((c <= 'Z') && (c >= 'A')) || (c == '#') || (c == '_')) return true;     
	else return false; 
}  

bool IsDigit(char c){          //判断是否为数字     
	if(c >= '0' && c <= '9')  return true;      
	else  return false; 
}  

void analyse(string fpin){ 
	string arr = "";
	char *ch = &fpin[0];
	while(*ch != NULL) { 
		arr = "";                   
		if(*ch == ' ' || *ch == '\t' || *ch == '\n') continue;                  
		if(IsLetter(*ch)){  
            while(IsLetter(*ch) || IsDigit(*ch) || (*ch == ':')) {  
				// if((*ch <= 'Z') && (*ch >= 'A'))  *ch = *ch + 32;     //小写字母
				arr = arr + (*ch); 
				ch++; 
			}  
            if(Iskey(arr)) cout<< "[" << arr << "\t$关键字" << "]" << endl;     
        	else if(arr.length() == 1){  
				if(flg) cout << "[" << arr << "\t$局部变量" << "]" << endl;
				else cout << "[" << arr << "\t$全局变量" << "]" << endl;
			}
			else cout << "[" << arr << "\t$普通标识符" << "]" << endl;
		}                     
		else if(IsDigit(*ch)){                    
			char *c = ch;
			while(IsDigit(*ch) || *ch == '.' && IsDigit(*(c++))){ 
				arr = arr + (*ch); 
				ch++; 
			}  
			cout << "[" << arr << "\t$无符号实数" << "]" << endl;   
		}         
		else 
			switch(*ch){    
            	case '+': 
               	case '-': 
               	case '*':   
				case '|':
						if(*ch != NULL && *(ch + 1) == '|'){
							while(*ch != NULL){	
								arr = arr + (*ch); 
								ch++; 
							}
							cout << "[" << arr << "\t$运算符" << "]" << endl;
							break;
						}            
			   	case '=':  
				   		if(*ch != NULL && *(ch + 1) == '='){
							while(*ch != NULL){	
								arr = arr + (*ch); 
								ch++; 
							}
							cout << "[" << arr << "\t$运算符" << "]" << endl;
							break;
						}
				case '&': 
						if(*ch != NULL && *(ch + 1) == '&'){
							while(*ch != NULL){	
								arr = arr + (*ch); 
								ch++; 
							}
							cout << "[" << arr << "\t$运算符" << "]" << endl;
							break;
						}
               	case '/': 
				   		if(*ch != NULL && *(ch + 1) == '/'){
							while(*ch != NULL){	
								arr = arr + (*ch); 
								ch++; 
							}
							cout << "[" << arr << "\t$普通标识符" << "]" << endl;
							break;
						}
			   			cout << "["  << *ch << "\t$运算符" << "]" << endl;
			   			ch++;
						break; 
               	case '(': 
               	case ')': 
               	case '[':  
               	case ']':                
               	case ';': 
               	case '.': 
               	case ',': 
				   		cout << "["  << *ch << "\t$界符" << "]" << endl;
						ch++;
						break;
               	case '{':
						flg = true;
						cout << "["  << *ch << "\t$界符" << "]" << endl;
						ch++;
						break;
				case '}':
						flg = false;
			   			cout << "["  << *ch << "\t$界符" << "]" << endl;
						ch++;
						break; 
               	case ':':
			   			{
							if(*ch != NULL && *(ch + 1) == ':'){
								while(*ch != NULL){	
									arr = arr + (*ch); 
									ch++; 
								}
								cout << "[" << arr << "\t$普通标识符" << "]" << endl;
								break;
							}
							while(*ch != NULL){	
								arr = arr + (*ch); 
								ch++; 
							}
				   			if(arr == ":=" || arr == ":") cout << "[" << arr << "\t$运算符" << "]" << endl;
				   			else cout << "[" << arr << "\t$无法识别字符" << "]" << endl;
						}
						break;
			   	case '>':
				   		{
				   			while(*ch != NULL){	
							   arr = arr + (*ch); 
							   ch++; 
							}
				   			if(arr == ">=" || arr == ">") cout << "[" << arr << "\t$运算符" << "]" << endl;
				   			else if(arr == ">>") cout << "[" << arr << "\t$输入控制符" << "]" << endl;
				   			else cout << "[" << arr << "\t$无法识别字符"<< "]" << endl;
						}
						break;
               	case '<':
				   		{
				   			while(*ch != NULL){	
								arr = arr + (*ch); 
								ch++; 
							}
				   			if(arr == "<=" || arr == "<") cout << "[" << arr << "\t$运算符" << "]" << endl;
				   			else if(arr == "<<") cout << "[" << arr << "\t$输出控制符" << "]" << endl;
				   			else if(arr[arr.length() - 1] == '>') cout << "[" << arr << "\t$头文件" << "]" << endl;
							else cout << "[" << arr << "\t$无法识别字符"<< "]" << endl;
						}
						break;
				case '"':
				   		{
				   			while(*ch != NULL){	
								arr = arr + (*ch); 
								ch++; 
							}
							cout << "[" << arr << "\t$字符串" << "]" << endl;
						}
						break;
				case '\'':
				   		{
						    while(*ch != NULL){	
						 		arr = arr + (*ch); 
						 		ch++; 
							}
							cout << "[" << arr << "\t$字符" << "]" << endl;
						}
						break;
			   	default:
				   		{
					   		while(*ch != NULL) {	
								   arr = arr + (*ch); 
								   ch++; 
							}
							cout << "[" << arr << "\t$无法识别字符"<< "]" << endl;
						}
						break;
			} 				  
	} 
}  

struct globalTableNode{
	bool var;     //函数是0，变量是1
	int id;       //变量/函数id
	string name;  //变量名/函数名
	string type;  //变量/函数类型
	vector<int> toLocalId;  //对应的局部函数地址
};
struct localTableNode{
	string funcName;  //函数名称
	int id; //局部变量id
	string name; //局部变量名
	string type; //局部变量类型
};
int cnt = 0;
vector<globalTableNode> globalTable; //全局符号表
vector<localTableNode> localTable;   //局部符号表
map<string, int> globalMap;         //全局符号表名字到地址映射
map<string, int> localMap;          //局部符号表名字到地址映射
string varType[7] = {"int", "double", "float", "byte", "char", "long", "void"}; //变量类型

vector<string> split(const string &str, const string &pattern){
    vector<string> res;
    if(str == "") return res;
    //在字符串末尾也加入分隔符，方便截取最后一段
    string strs = str + pattern;
    size_t pos = strs.find(pattern);

    while(pos != strs.npos){
        string temp = strs.substr(0, pos);
        res.push_back(temp);
        //去掉已分割的字符串,在剩下的字符串中进行分割
        strs = strs.substr(pos+1, strs.size());
        pos = strs.find(pattern);
    }

    return res;
}


bool isVarType(string tar){
	for (int i = 0; i < 7; i++){
		if(tar == varType[i]) return true;
	}
	return false;
}
bool falg; //全局变量
string func;

void pushToGlobal(string src){
	if(src == "}"){
		falg = 0;
		func = "";
		return;
	}
	vector<string> tmp = split(src, " ");

	int i = 0;
  	for (; i < tmp.size(); i++){
		if(isVarType(tmp[i])) break;
	}
	if(i >= tmp.size()) return;

	if((i+1) < tmp.size() && isVarType(tmp[i+1])) i++;
	i++;
	cout << tmp[i] << " ";
	string type = tmp[i - 1];
	if(!falg && (tmp[i][tmp[i].size()-1] == '{' || tmp[i][tmp[i].size()-1] == ')' || (i+1 < tmp.size() && tmp[i+1] == "("))){
		cout << tmp[i] << endl;
		globalTableNode gtn;
		falg = 1;
		gtn.var = 0;
		string str = "";
		for (int j = 0; j < tmp[i].size(); j++){
			if(tmp[i][j] == '(') break;
			str += tmp[i][j];
		}
		func = str;
		gtn.name = str;
		gtn.type = tmp[i-1];
		gtn.id = cnt;
		globalMap[str] = cnt++;
		globalTable.push_back(gtn);
	} 
	
	while(i < tmp.size() && (tmp[i][tmp[i].size()-1] == ';' || (i+1 < tmp.size() && tmp[i+1] == "=") || tmp[i][tmp[i].size()-1] == ',')){
		cout << tmp[i] << endl;
		globalTableNode gtn;
		localTableNode ltn;
		if(!falg) gtn.var = 1;
		string str = "";
		for (int j = 0; j < tmp[i].size(); j++){
			if (tmp[i][j] == ';' || tmp[i][j] == '=' || tmp[i][j] == ',') break;
			str += tmp[i][j];
		}
		if(!falg){
			gtn.name = str;
			gtn.type = type;
			gtn.id = cnt;
			globalMap[str] = cnt++;
			globalTable.push_back(gtn);
		}else{
			ltn.funcName = func;
			ltn.name = str;
			ltn.type = type;
			ltn.id = cnt;
			localMap[str] = cnt;
			globalTable[globalMap[func]].toLocalId.push_back(cnt);
			cnt++;
			localTable.push_back(ltn);
		}
		i++;
	}
	//cout << gtn.name << " " << gtn.type << " " << gtn.var << endl;
}

void print(){
	cout << "全局符号表：" << endl;
	cout << "函数/变量名\t类型\t变量/函数类型" << endl;
	for(auto v : globalTable){
		cout << v.name << "\t\t" << (v.var ? ("变量") : ("函数")) << "\t" << v.type << endl;
	}
	cout << "局部符号表：" << endl;
	cout << "函数名\t变量名\t变量类型" << endl;
	for(auto v : localTable){
		cout << v.funcName << "\t" << v.name << "\t" << v.type << "\t" << endl;
	}
	cout << endl;
}

int main() {
	string a[10000];
	int i = 0;
	ifstream infile;
	infile.open("test.txt");
	ifstream in("test.txt");
	if(!infile || !in){
		cerr<<"open error!!"<<endl;
		exit(1);
	}
	while(infile){
		infile >> a[i++];
	}
	infile.close();
	string src;
	while(getline(in, src)){
		pushToGlobal(src);
	}
	print();

	cout << "\n********************分析如下*********************" << endl;
	for(int j = 0; j <= i; j++){
		//analyse(a[j]);
	}
	cout << endl;
	//system("pause");
	return 0;
} 