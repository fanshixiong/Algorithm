#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#include <fstream>

using namespace std; 

#define MAXN 16

string key[MAXN]={"begin", "end", "if", "then", "else", "while", "write", "do", "call", 
				"const", "char", "until", "procedure", "repeat", "int"}; 

//全局符号表
struct globalTableNode{
	bool var;    
	int id;      
	string name;  
	string type; 
	vector<int> toLocalId; 
	bool specification; 
};

//局部符号表
struct localTableNode{
	string funcName; 
	int id; 
	string name;
	string type;
	int state; 
	bool specification; 	
	bool isRepeation;  
};

typedef struct HashNode{
	localTableNode data; 
	int isNull;    
}HashTable;

const int MAX = 1100;
HashTable hashTable[MAX];


int global_cnt = 0, local_cnt = 0;
int cnt = 0;

vector<globalTableNode> globalTable;
vector<localTableNode> localTable; 


map<string, int> globalMap;     
map<string, int> localMap;         

string varType[7] = {"int", "double", "float", "byte", "char", "long", "void"};


bool falg; //全局变量
string func;
