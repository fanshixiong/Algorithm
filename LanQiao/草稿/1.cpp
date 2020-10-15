#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

struct cmp{
	bool operator()(const pair<int, int> p1, const pair<int, int> p2){
		return p1.first < p2.first;
	}
};
 
int lowbit(int x){
	return x & (-x);
}
int a[maxn];
int modify(int x, int val){
	while(x <= maxn){
		a[x] += val;
		x += lowbit(x);
	}
}
int getsum(int x){
	int sum = 0;
	while(x){
		sum += a[x];
		x -= lowbit(x);
	}
	return sum; 
}

// 树状数组求逆序对
// ans += i-getsum(num[i]) ;



const int n = 10;
//并查集
int par[n];
int find(int x){
	return x == par[x] ? x : par[x] = find(par[x]);
} 
void union1 (int x, int y){
	x = find(x);
	y = find(y);
	if(x == y) return;
	par[y] = x;
	//par[x] = y;
}


int main(){
	
	int p22 = 10;
	stringstream ss;
	ss << p22;
	string str = ss.str();
	cout << str << endl;
	
	string p2 = "23";
	stringstream sp(p2);
	int t;
	sp >> t;
	cout << t << endl;
	
	
	
	
	
	priority_queue<pair<int, int>, vector< pair<int, int> >, cmp> q;
	
	freopen("1.txt", "r", stdin);
	
	
	string s = "FDSFagdsggsdfg";
	map<char, int> pp;
	for(int i=0; i < s.size(); i++) pp[s[i]]++;
	
	

        map<char, int> p;
        for(int i=0; i < s.size(); i++) p[s[i]] = i;
    
        stack<int> st;
        set<char> vis;
        for(int i = 0; i < s.size(); i++){
            if(vis.count(s[i])) continue;
            while(!st.empty() && st.top() > s[i]){
                if(p[st.top()] <= i) break;
                vis.erase(st.top());
                st.pop();
            }

            st.push(s[i]);
            vis.insert(s[i]);
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
	
	
	
	
	return 0;
} 


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* ans;
bool lca(TreeNode *root, TreeNode *p, TreeNode *q){
	if(root == NULL) return false;
	
	bool l = lca(root->left, p, q);
	bool r = lca(root->right, p, q);
	
	if((l && r) || ((l || r) || (root->val == p->val || root->val == q->val))){
		ans = root;
	}
	
	return (l || r) || (root->val == p->val || root->val == q->val);
}




//Morris
TreeNode *getSuccessor(TreeNode *root){
	TreeNode *node = root->left;
	while(node->right && node->right != root) node=node->right;
	return node;
}

void helper(){
}
void morris(TreeNode *root){
	TreeNode *node = root;
	while(node){
		if(node->left == NULL){
			helper();
			node = node->right;
		}
		else{
			TreeNode *succ = getSuccessor(node);
			if(succ->right == NULL){
				succ->right = node;
				node = node->left;
			}
			else{
				succ->right = NULL;
				helper();
				node = node->right;
			}
		}
	}
}

class Trie{
private:
	bool isWord = false;
	Trie *next[26] = {NULL};
public:
	Trie(){
	}
	
	void insert(string word){
		Trie *root = this;
		for(int i = 0; i < word.size(); i++){
			int p = word[i]-'a';
			if(root->next[p] == NULL) root->next[p] = new Trie();
			root = root->next[p];
		}
		root->isWord = true;
	}
	
	bool search(string word){
		Trie *root = this;
		for(int i = 0; i < word.size(); i++){
			int p = word[i]-'a';
			if(root->next[p] == NULL) return false;
			root = root->next[p];
		}
		return root->isWord;
	}
};


// KMP
void getNext(string s, vector<int> &next){
	int i = 0, j = -1;
	next[0] = -1;
	while(i < s.size()){
		if(j == -1 || s[i] == s[j]){
			i++; j++;
			next[i] = j;
		}
		else j = next[j];
	}
}

int kmp(string s, string p){
	int i = 0, j = 0;
	vector<int> next(p.size());
	getNext(p, next);
	
	while(i < s.size() && j < p.size()){
		if(j == -1 || s[i] == p[j]){
			i++; j++;
		}
		else j = next[j];
	}
	
	if(j >= p.size()) return i-j;
	else return -1;
}

//约瑟夫环
int josephus1(int n, int m){
	int f = 0;
	for(int i = 2; i != n+1; i++) f = (f+m)%i;
	return f;
} 

int josephus2(int n, int m){
	if(n == 1) return 0;
	return (josephus(n-1, m) + m) % n;
}

int qsm(int n, int m){
	int ans = 1;
	while(n > 0){
		if(n & 1) ans *= x;
		n >>= 1;
		x *= x;
	}
	return ans;
}

// 背包
int f(){
	for(int i = 1; i <= n; i++){
		for(int j = w[i]; j <= m; j++) h[j] = max(h[j], h[j-w[i]]+v[i]);
		//for(int j=m; j>=w[i]; j--) h[j] = max(h[j], h[j-w[i]]+v[i]);
	}
} 

int sum1(int n){
	int cnt = 0;
	while(n){
		cnt++;
		n &= (n-1);
	}
	return cnt;
}
