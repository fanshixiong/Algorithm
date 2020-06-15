#include "MYLEX.h"

bool Iskey(string c){        
	for(int i = 0; i < MAXN; i++) {  
		if(key[i].compare(c) == 0)  {
			return true;
		} 
	}
	return false; 
} 
 
bool IsLetter(char c) {       
	if(((c <= 'z') && (c >= 'a')) || ((c <= 'Z') && (c >= 'A')) || (c == '#') || (c == '_')) {
		return true;
	}     
	else{
		return false;
	} 
}  

bool IsDigit(char c){          
	if(c >= '0' && c <= '9') {
		return true;
	}      
	else{
		return false; 
	}
}  

int hashToInt(string s){
	int hash = 0;
	int offset = 'a' - 1;
	for(string::const_iterator it=s.begin(); it != s.end(); ++it) 
	{
  		hash = hash << 1 | (*it - offset);
	}
	return abs(hash);
}


void initHashTable() 
{
	for (int i = 0; i < MAX; i++)
	{
		hashTable[i].isNull = 1;    //初始状态为空 
	}
}

int getHashAddress(int key)
{
	return key % 111;
}

void insert(int key, localTableNode node)
{
	int address = getHashAddress(key);
	if (hashTable[address].isNull == 1)
	{
		hashTable[address].data = node;
		hashTable[address].isNull = 0;
	}else
	{   
		while (hashTable[address].isNull == 0 && address < MAX)
		{
			if (hashTable[address].data.name == node.name && node.state == hashTable[address].data.state && node.funcName == hashTable[address].data.funcName) {
				node.isRepeation = 1;
			}
			address++;       
		}
		if (address >= MAX)
		{   
			cout << "Hash表溢出 " << endl;
			return;
		}
		hashTable[address].data = node;
		hashTable[address].isNull = 0;
	}
}

int find(int key, localTableNode node)	{
	int address = getHashAddress(key);
	while (!(hashTable[address].isNull == 0 && hashTable[address].data.name == node.name && address < MAX)){
		address++;
	}

	if (address >= MAX){
		address = -1;
	}
	return address;
}

vector<string> split(const string &str, const string &pattern){
    vector<string> res;
    if(str == "") return res;
    string strs = str + pattern;
    size_t pos = strs.find(pattern);

    while(pos != strs.npos){
        string temp = strs.substr(0, pos);
        res.push_back(temp);
        strs = strs.substr(pos+1, strs.size());
        pos = strs.find(pattern);
    }

    return res;
}


bool isVarType(string tar)
{
	for (int i = 0; i < 7; i++)
	{
		if(tar == varType[i]){
			return true;
		}
	}
	return false;
}


bool isValid(string str)
{
	if(str[0] >= '0' && str[0] <= '9'){
		return false;
	}
	for (int i = 0; i < str.size(); i++)
	{
		if((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_') {
			continue;
		}
		else {
			return false;
		}
	}
	for(auto x : varType)
	{
		if(x == str) {
			return false;
		}
	}

	return true;
}


void pushToGlobal(string src){
	if(src == "}")
	{
		falg = 0;
		cnt--;
		func = "";
		return;
	}
	for(auto c : src)
	{
		if(c == '{') cnt++;
		if(c == '}') cnt--;
	}
	vector<string> tmp = split(src, " "); 
	int i = 0;
  	for (; i < tmp.size(); i++)
	  {
		if(isVarType(tmp[i])) {
			break;
		} 
	}
	if(i >= tmp.size()) {
		return;
	} 

	if((i+1) < tmp.size() && isVarType(tmp[i+1])) {
		i++;
	} 
	i++;
	string type = tmp[i - 1];

	
	if(!falg && (tmp[i][tmp[i].size()-1] == '{' || tmp[i][tmp[i].size()-1] == ')' || (i+1 < tmp.size() && tmp[i+1] == "(")))
	{
		globalTableNode gtn;
		falg = 1;
		gtn.var = 0;
		string str = "";
		for (int j = 0; j < tmp[i].size(); j++)
		{
			if(tmp[i][j] == '(') break;
			str += tmp[i][j];
		}
		int hash = hashToInt(str);
		func = str; 
		if(!isValid(str)) gtn.specification = 1;
		gtn.name = str;
		gtn.type = tmp[i-1];
		gtn.id = global_cnt;
		globalMap[str] = global_cnt++;
		globalTable.push_back(gtn);
	} 

	while(i < tmp.size() && (tmp[i][tmp[i].size()-1] == ';' || (i+1 < tmp.size() && tmp[i+1] == "=") || tmp[i][tmp[i].size()-1] == ','))
	{
		globalTableNode gtn;
		localTableNode ltn;
		string str = "";
		for (int j = 0; j < tmp[i].size(); j++)
		{
			if (tmp[i][j] == ';' || tmp[i][j] == '=' || tmp[i][j] == ',') break;
			str += tmp[i][j];
		}
		int hash = hashToInt(str);
		if(!cnt)
		{
			if(!isValid(str)){
			 	gtn.specification = 1;
			}
			gtn.var = 1;
			gtn.name = str;
			gtn.type = type;
			gtn.id = global_cnt;
			globalMap[str] = global_cnt++;
			globalTable.push_back(gtn);
		}
		else
		{
			ltn.specification = 0;
			ltn.isRepeation = 0;
			if(!isValid(str)) ltn.specification = 1;
			ltn.funcName = func;
			ltn.name = str;
			ltn.type = type;
			ltn.id = local_cnt;
			ltn.state = cnt;
			insert(hashToInt(str), ltn);
			if(localMap[str]) ltn.isRepeation = 1;
			localMap[str] = local_cnt;
			globalTable[globalMap[func]].toLocalId.push_back(local_cnt);
			local_cnt++;
			localTable.push_back(ltn);
		}
		i++;
	}
}
