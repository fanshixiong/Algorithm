#include<iostream> 
#include<fstream>
#include<string> 
using namespace std; 

#define MAX 16           
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
	else  return false; 
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
        	else   cout << "[" << arr << "\t$普通标识符" << "]" << endl;   
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
            	case'+': 
               	case'-': 
               	case'*':               
			   	case'=':  
               	case'/': 
			   			cout << "["  << *ch << "\t$运算符" << "]" << endl;
			   			ch++;
						break; 
               	case'(': 
               	case')': 
               	case'[':  
               	case']':                
               	case';': 
               	case'.': 
               	case',': 
               	case'{':  
               	case'}':
			   			cout << "["  << *ch << "\t$界符" << "]" << endl;
						ch++;
						break; 
               	case':':
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
			   	case'>':
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
               	case'<':
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
		
int main() {
	string a[10000];
	int i = 0;
	ifstream infile;
	infile.open("test.txt");
	if(!infile){
		cerr<<"open error!!"<<endl;
		exit(1);
	}
	while(infile){
		infile >> a[i++];
	}
	infile.close();
	cout<<"\n********************分析如下*********************"<<endl;
	for(int j = 0; j <= i; j++){
		analyse(a[j]);
	}
	cout<<endl;     
	return 0;
} 