// 前缀树实现

#include <iostream> 
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class TrieNode{
	public: 
	const static int MaxBranchNum = 26;     //节点最大分支数 
	TrieNode *nextBranch[MaxBranchNum];     //指针数组 代表 26个字母 
	bool isEnd;                             //判断是否是一个单词的结尾 
	int count;                              //单词出现的次数 
	string word;                            //当isEnd == True时保存相应的单词 
	TrieNode():count(0),isEnd(false){
		memset(nextBranch, NULL, sizeof (TrieNode*)*MaxBranchNum); //初始化数组
	};
	void put(char ch){                      //插入字母ch 相当于ch在nextBranch数组中的指针实例化 
		if (nextBranch[ch-'a'] == NULL) nextBranch[ch-'a'] = new TrieNode();
	} 
	TrieNode *get(char ch){                //获取ch对应的指针，不存在则返回空 
		return nextBranch[ch-'a'];
	}
	bool containsKey(char ch){              //判断当前节点是否包含字母ch 
		return nextBranch[ch-'a'] != NULL;
	}
	void setEnd(){
		isEnd = true;
	}
	bool isWord(){
		return isEnd;
	}
};

class Trie{
	public:
		Trie(){
			root = new TrieNode();
		}
		~Trie(){
			destroy(this->root);
		}
		void insert(const string word)               //插入单词 
		{
			if(word.size() == 0)return;
			for (int i = 0; i < word.size(); i++)
				if (word[i] < 'a' || word[i] > 'z') 
					return;
			TrieNode *node = root;
			for (int i = 0; i <word.size(); i++){
				if(!node->containsKey(word[i]))
					node -> put(word[i]);
				node = node -> get(word[i]);
			}
			if (node -> word.size() == 0)
				node -> word.assign(word);
			node->count++;
			node ->setEnd();
		}
		TrieNode *searchPrefix(const string prefix)   //查找前缀prefix ，并返回最后的节点
		{
			TrieNode *node = root;
			for (int i = 0; i < prefix.size(); i++){
				if (prefix[i]<'a' || prefix[i] > 'z') return NULL;
				if (node -> containsKey(prefix[i]))
					node = node -> get(prefix[i]);
				else
					return NULL;
			}
			return node;
		}
		int search(const string word)                 //查找单词
	    {
	    	TrieNode *node = searchPrefix(word);
	    	return node ? node->count:0;
		}
		bool startsWith(const string prefix)         //如果存在任意单词以prefix为前缀，返回true 
		{
			return searchPrefix(prefix) != NULL;
		}
		void printAll()                               //打印当前字典中所有单词
		{
			print(this->root );
		}
		void printPre(const string prefix)            //但因以prefix为前缀的所有单词
		{
			if (prefix.size() == 0) printAll();
			else{
				TrieNode *node = root;
				for (int i = 0; i < prefix.size(); i++)
					if (node -> containsKey(prefix[i]))
						node = node -> get(prefix[i]);
					else
						return;
				
					print(node);
				}	
		}	
	private:
		TrieNode *root;
		void destroy(TrieNode *root)                  //销毁所有root 
		{
			if (root == NULL) return;
			for (int i = 0; i < root->MaxBranchNum; i++)
				destroy(root->nextBranch[i]);
			delete root;
			root = NULL;
		}
		void print(TrieNode *root)                    //打印以root为根的所有单词 
		{
			if(root == NULL) return;
			TrieNode *node = root;
			if (root -> word.size() != 0) cout << root ->word <<endl;
			for (int i = 0; i <root ->MaxBranchNum; i++)
				print(root->nextBranch[i]);
		}
};
int main(){  
	Trie* a = new Trie(); 
	a->insert("hello"); 
	a->insert("hello"); 
	a->insert("hi");    
	a->insert("beauty");    
	a->insert("helloworld");    
	a->insert("word");    
	cout<<a->search("hello");//2    
	a->printAll();    
	a->printPre("h");    
	delete a;    
	return 0;
}

