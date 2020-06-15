#include "LEX.cpp"
#include "MAlex.cpp"
//输出
void print(){
	cout << "[ 全局符号表：\t\t                 ]" << endl;
	cout << "[ 函数/变量名\t类型\t变量/函数类型  ]" << endl;
	for(auto v : globalTable){
		cout << "[ " << v.name << "\t\t" << (v.var ? ("变量") : ("函数")) << "\t" << v.type << " ]" << endl;
	}
	
	cout << "[ 局部符号表：\t\t\t\t\t                   ]" << endl;
	cout << "[ 所属函数\t变量名\t变量类型\t合法性\t作用域 ]" << endl; 
	for(auto v : localTable){
		string name = v.name;
		int address = find(hashToInt(name), v);
		localTableNode x = hashTable[address].data;
		cout << "[ " << x.funcName << "\t\t" << x.name << "\t" << x.type << "\t\t" << (x.specification ? "不合法  " : "      \t") << x.state << " ]" << endl;
	}
	cout << endl;
}

int main() {
	string a[10000];
	int i = 0;
	ifstream infile;
	infile.open("data.txt");
	ifstream in("data.txt");
	if(!infile || !in){
		cerr<<"open error!!"<<endl;
		exit(1);
	}
	initHashTable();
	while(infile){
		infile >> a[i++];
	}
	infile.close();
	string src;
	while(getline(in, src)){
		pushToGlobal(src);
	}
	print();

	MAlex mlex;
	mlex.COPE();
	return 0;
} 