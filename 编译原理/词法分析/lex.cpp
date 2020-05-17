#include <bits/stdc++.h>

#define _KEY_WORDEND "waiting for your expanding"
using namespace std;
typedef struct{ //词的结构，二元组形式（单词种别，单词自身的值）
	int typenum; //单词种别
	char * word;
}WORD;
char input[255];
char token[255] = "";
int p_input; //指针
int p_token;
char ch;
char * rwtab[] = { "begin","if","then","while","do","end","int","main",
                        "else","float","double","return","cout",_KEY_WORDEND };
 
WORD * scanner();//扫描
 
int main(){
	int over = 1;
	WORD* oneword = new WORD;
 
	//实现从文件读取代码段
	cout << "read something from data.txt" << endl;
	FILE *fp;
	ifstream infile;
	infile.open("data.txt");
	if(!infile){
        printf("Not found file!\n");
        return 0;
    } else {
		while (infile){
			infile >> input;
			cout << input << endl;
			p_input = 0;
            printf("your words:\n%s\n", input);
            while (over < 1000 && over != -1){
            	oneword = scanner();
                if (oneword -> typenum < 1000){
                    if(oneword -> typenum != 999)
                         cout << "[  "<< oneword -> typenum <<"\t"<< oneword -> word <<"  ]"<< endl;
                    }
                    over = oneword -> typenum;
                }
				infile >> input;
			}
        }
    return 0;
}
 
//从输入缓冲区读取一个字符到ch中
char m_getch(){
	ch = input[p_input];
	p_input++;
	return ch;
}
 
//去掉空白符号
void getbc(){
	while (ch == ' ' || ch == 10){
		ch = input[p_input];
		p_input++;
	}
}
 
//拼接单词
void concat(){
	token[p_token] = ch;
	p_token++;
	token[p_token] = '\0';
}
 
//判断是否字母
int letter(){
	if (ch >= 'a'&&ch <= 'z' || ch >= 'A'&&ch <= 'Z')
		return 1;
	else
		return 0;
}
 
//判断是否数字
int digit(){
	if (ch >= '0'&&ch <= '9')
		return 1;
	else
		return 0;
}
 
//检索关键字表格
int reserve(){
	int i = 0;
	while(strcmp(rwtab[i], _KEY_WORDEND)){
		if (!strcmp(rwtab[i], token))
			return i + 1;
		i++;
	}
	return 10;//如果不是关键字，则返回种别码10
}
 
//回退一个字符
void retract(){
	p_input--;
}
 
//词法扫描程序
WORD * scanner(){
	WORD * myword = new WORD;
	myword -> typenum = 10;  //初始值
	myword -> word = "";
	p_token = 0;   //单词缓冲区指针
	m_getch();
	getbc();//去掉空白
 
	if (letter()){//判断读取到的首字母是字母
	        //如int
		while (letter() || digit()){
			concat(); //连接
			m_getch();
		}
		retract(); //回退一个字符
		myword -> typenum = reserve();//判断是否为关键字，返回种别码
		myword -> word = token;
		return myword;
	}
	else if (digit()){  //判断读取到的单词首字符是数字
		while (digit()){ //所有数字连接起来
			concat();
			m_getch();
		}
		retract();
		//数字单词种别码统一为20，单词自身的值为数字本身
		myword -> typenum = 20;
		myword -> word = token;
		return(myword);
	}
	else switch (ch) {
		case '=':
			m_getch();//首字符为=,再读取下一个字符判断
			if (ch == '=') {
				myword -> typenum = 39;
				myword -> word = "==";
				return(myword);
			}
			retract();//读取到的下个字符不是=，则要回退，直接输出=
			myword -> typenum = 21;
			myword -> word = "=";
			return(myword);
			break;
		case '+':
			myword -> typenum = 22;
			myword -> word = "+";
			return(myword);
			break;
		case '-':
			myword -> typenum = 23;
			myword -> word = "-";
			return(myword);
			break;
        case '/'://读取到该符号之后，要判断下一个字符是什么符号，判断是否为注释
            m_getch();//首字符为/,再读取下一个字符判断
			if (ch == '*'){ // 说明读取到的是注释
				m_getch();

				while(ch != '*') {
					m_getch();//注释没结束之前一直读取注释，但不输出
					if(ch == '*') {
						m_getch();
						if(ch == '/'){//注释结束
							myword->typenum = 999;
							myword->word = "注释";
							return (myword);
							break;
						}
					}
	
				}
 			} else {
                retract();//读取到的下个字符不是*，即不是注释，则要回退，直接输出/
 
                myword->typenum = 25;
                myword->word = "/";
                return (myword);
                break;
            }
        case '*':
			myword->typenum = 24;
			myword->word = "*";
			return(myword);
			break;
		case '(':
			myword->typenum = 26;
			myword->word = "(";
			return(myword);
			break;
		case ')':
			myword->typenum = 27;
			myword->word = ")";
			return(myword);
			break;
		case '[':
			myword->typenum = 28;
			myword->word = "[";
			return(myword);
			break;
		case ']':
			myword->typenum = 29;
			myword->word = "]";
			return(myword);
			break;
		case '{':
			myword->typenum = 30;
			myword->word = "{";
			return(myword);
			break;
		case '}':
			myword->typenum = 31;
			myword->word = "}";
			return(myword);
			break;
		case ',':
			myword->typenum = 32;
			myword->word = ",";
			return(myword);
			break;
		case ':':
			m_getch();
			if (ch == '=') {
				myword -> typenum = 18;
				myword -> word = ":=";
				return(myword);
				break;
			}
			else {
				retract();
				myword -> typenum = 33;
				myword -> word = ":";
				return(myword);
				break;
			}
		case ';':
			myword -> typenum = 34;
			myword -> word = ";";
			return(myword);
			break;
		case '>':
			m_getch();
			if (ch == '='){
				myword->typenum = 37;
				myword->word = ">=";
				return(myword);
				break;
			}
			retract();
			myword->typenum = 35;
			myword->word = ">";
			return(myword);
			break;
		case '<':
			m_getch();
			if (ch == '='){
				myword->typenum = 38;
				myword->word = "<=";
				return(myword);
				break;
			}
			else if(ch == '<'){
				myword->typenum = 42;
				myword->word = "<<";
				return(myword);
				break;
			}
			else{
				retract();
				myword->typenum = 36;
				myword->word = "<";
				return (myword);
			}
		case '!':
			m_getch();
			if (ch == '='){
				myword->typenum = 40;
				myword->word = "!=";
				return(myword);
				break;
			}
			retract();
			myword->typenum = -1;
			myword->word = "ERROR";
			return(myword);
			break;
		case ' " ':
			myword->typenum = 41;
			myword->word = " \" ";
			return(myword);
			break;
		case '\0':
			myword->typenum = 1000;
			myword->word = "OVER";
			return(myword);
			break;
		case '#':
			myword->typenum = 0;
			myword->word = "#";
			return (myword);
			break;
		default:
			myword->typenum = -1;
			myword->word = "ERROR";
			return(myword);
			break;
	}
}
	
	