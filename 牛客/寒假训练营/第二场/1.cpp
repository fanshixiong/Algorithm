/*
实现一个简单的代码版本控制系统，要求实现如下功能：
*/

#include<bits/stdc++.h>
using namespace std;

Class Git{
private:
	vector<vector<string> > operations; //命令集合
	unordered_map<string, int> name2id;
	unordered_map<string, string> name2file;
	unordered_map<string, string> file2name;
	int id = 1;
public:
	void analysis(vector<string> op){
		if(op[0] == "commit") commit(op);
		else if(op[0] == "hist") hist(op);
		else remove(op);
		operations.push_back(op);
	}

	/*
		提交一个版本和说明，文件为test.txt，程序需要返回一个生成的版本号
		commit（提交版本），命令： commit -m "test" -f "D://test.txt" 
		输出：add revision success, id：1
	*/
	void commit(vector<string> op){
		string name = op[2];
		name2id[name] = id++;
		if(op[4] == ""){
			cout << "文件名为空!" << endl;
			return;
		}
		name2file[name] = op[4];
		file2name[op[4]] = name;
		cout << "add revision success, id：" << id-1 << endl;
	}
	
	/*
		查看历史记录，需要按时间逆序列出[版本号，说明，和改动文件]/[该命令之前的命令历史记录]，参数不共存
		history（历史记录），命令： hist [-v]|[-c] 
		输出：hist -v : 1 test D://test.txt
      	hist -c : commit -m "test" -f "D://test.txt"
		hist -v

	*/
	void hist(vector<string> op){
		if(operations.size() == 0){
			cout << "没有命令记录!" << endl;
			return;
		}
		vector<string> lastOp = operations.back();
		string name = lastOp[2];
		if(op[1][1] == 'v'){
			if(!name2file.count(name) || name2file[name] == ""){
				cout << id  << " " << name << " 文件已删除" << endl;
				return;
			}
			cout << name2id[name] << " " << name.substr(1, name.size() - 2) << " " << name2file[name].substr(1, name2file[name].size()-2) << endl;
		}
		else{
			for(auto s : lastOp) cout << s << " ";
			cout << endl;
		}
	}

	/*
	bonus： 从仓库中移除文件
			remove（移除文件）， 命令：remove -f "D://text.txt" 
			输出：remove file D://text.txt success
		op: 命令
	*/
	void remove(vector<string> op){
		if(!file2name.count(op[2]) || file2name[op[2]]){
			cout << "没有这个文件!" << endl;
			return;
		}
		string name = file2name[op[2]];
		name2file[name] = "";
		cout << "remove file " << op[2] << " success" << endl;
	}
}

int main(){
	return 0;
}