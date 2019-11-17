// ǰ׺��ʵ��

#include <iostream> 
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class TrieNode{
	public: 
	const static int MaxBranchNum = 26;     //�ڵ�����֧�� 
	TrieNode *nextBranch[MaxBranchNum];     //ָ������ ���� 26����ĸ 
	bool isEnd;                             //�ж��Ƿ���һ�����ʵĽ�β 
	int count;                              //���ʳ��ֵĴ��� 
	string word;                            //��isEnd == Trueʱ������Ӧ�ĵ��� 
	TrieNode():count(0),isEnd(false){
		memset(nextBranch, NULL, sizeof (TrieNode*)*MaxBranchNum); //��ʼ������
	};
	void put(char ch){                      //������ĸch �൱��ch��nextBranch�����е�ָ��ʵ���� 
		if (nextBranch[ch-'a'] == NULL) nextBranch[ch-'a'] = new TrieNode();
	} 
	TrieNode *get(char ch){                //��ȡch��Ӧ��ָ�룬�������򷵻ؿ� 
		return nextBranch[ch-'a'];
	}
	bool containsKey(char ch){              //�жϵ�ǰ�ڵ��Ƿ������ĸch 
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
		void insert(const string word)               //���뵥�� 
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
		TrieNode *searchPrefix(const string prefix)   //����ǰ׺prefix �����������Ľڵ�
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
		int search(const string word)                 //���ҵ���
	    {
	    	TrieNode *node = searchPrefix(word);
	    	return node ? node->count:0;
		}
		bool startsWith(const string prefix)         //����������ⵥ����prefixΪǰ׺������true 
		{
			return searchPrefix(prefix) != NULL;
		}
		void printAll()                               //��ӡ��ǰ�ֵ������е���
		{
			print(this->root );
		}
		void printPre(const string prefix)            //������prefixΪǰ׺�����е���
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
		void destroy(TrieNode *root)                  //��������root 
		{
			if (root == NULL) return;
			for (int i = 0; i < root->MaxBranchNum; i++)
				destroy(root->nextBranch[i]);
			delete root;
			root = NULL;
		}
		void print(TrieNode *root)                    //��ӡ��rootΪ�������е��� 
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

