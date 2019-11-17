/*小蓝赛：两个数的异或和 
*/
#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
#define MAXN 100000
int tol; 				//节点个数
int ch[32*MAXN][2]; 			//边的值
class Tree{
public: 
	Tree(){ 
		tol=1;
		ch[0][0]=ch[0][1]=0;
	}
	void insert(int x){ //往 01字典树中插入 x 
		int u=1;
	    for(int i=30;i>=0;i--){
	        int v=(x>>i)&1;
	        if(!ch[u][v])
	        	ch[u][v]= ++tol;
	        u=ch[u][v];  
	    }
	}
	int query(int x){				 //查询所有数中和 x异或结果最大的数 
	    int u=1;
	    int res = 0;
	    for(int i=30;i>=0;i--){
	        int v=(x>>i)&1;
	        if(ch[u][v^1]){
				u=ch[u][v^1];
				res |= 1 << i;
				
			}
	        else u=ch[u][v];
	    }
	    return res; 
	}
	int max_xor(){
		int n;
		cin >> n;
		vector<int> nums(n);
		int res = 0;
		for (int i = 0; i < n; i++)	{
			cin >> nums[i];
			insert(nums[i]);
			res = max(res, query(nums[i]));
			cout << nums[i] << "  " << (query(nums[i]) ^ nums[i]) << endl;
		}
		return res;
	}
};
int main(){
	Tree test;
	cout << test.max_xor() << endl;
	
	return 0;
}
/*  错误 
#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
#define MAXN 100000
int tol; 				//节点个数
int val[32*MAXN]; 			//点的值
int ch[32*MAXN][2]; 			//边的值
class Tree{
public: 
	Tree(){ 
		tol=1;
		ch[0][0]=ch[0][1]=0;
	}
	void insert(int x){ //往 01字典树中插入 x 
		int u=0;
	    for(int i=32;i>=0;i--){
	        int v=(x>>i)&1;
	        if(!ch[u][v]){
				ch[tol][0]=ch[tol][1]=0; 
	            val[tol]=0;  
	            ch[u][v]=tol++;  
	        }
	        u=ch[u][v];  
	    }
	    val[u]=x; 
	}
	int query(int x){				 //查询所有数中和 x异或结果最大的数 
	    int u=0;
	    for(int i=32;i>=0;i--){
	        int v=(x>>i)&1;
	        if(ch[u][v^1]) u=ch[u][v^1];
	        else u=ch[u][v];
	    }
	    return val[u]; 
	}
	int max_xor(){
		int n;
		cin >> n;
		vector<int> nums(n);
		int res = 0;
		for (int i = 0; i < n; i++)	{
			cin >> nums[i];
			insert(nums[i]);
			res = max(res, query(nums[i]) ^ nums[i]);
			cout << nums[i] << "   " << query(nums[i]) << endl;
		}
		return res;
	}
};
int main(){
	Tree test;
	cout << test.max_xor() << endl;
	
	return 0;
}
*/
