#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int maxn = 30;
class Velco{
	int n, cnt;
	string a, b, c;
	vector<int> A, B, C;
	vector<int> num, next;
	vector<bool> vis;
	public:
	Velco(){
		cnt=0;
		A.resize(maxn); B.resize(maxn); C.resize(maxn); 
		num.resize(maxn); next.resize(maxn); vis.resize(maxn);
		cin >> n;
		cin >> a >> b >> c;
		for (int i = 0; i < n; i++){
			A[i] = a[i]-'A';
			B[i] = b[i]-'A';
			C[i] = c[i]-'A';
		}
		for (int i = n-1; i>=0; i--){
			if (!vis[A[i]]){
				vis[A[i]]=1;
				next[cnt++]=A[i];
			}
			if (!vis[B[i]]){
				vis[B[i]]=1;
				next[cnt++]=B[i];
			}
			if(!vis[C[i]]){
				vis[C[i]]=1;
				next[cnt++]=C[i];
			}
			num[i]=-1;
		}
		for (int i = 0; i < n; i++)
			vis[i]=0;
	}
	bool Prune(){
		if(num[A[0]]+num[B[0]]>=n)
			return true;
		for (int i = n-1; i>=0; i--){
			int x=num[A[i]];
			int y=num[B[i]];
			int z=num[C[i]];
			if(x==-1 || y==-1 || z==-1) 
				continue;
			if((x+y)%n!=z && (x+y+1)%n!=z)
				return true;
		}
		return false;
	}
	bool Judge(){
		int cmt=0;
		for (int i = n-1; i>=0; i--){
			int x=num[A[i]];
			int y=num[B[i]];
			int z=num[C[i]];
			if((x+y+cmt)%n != z)
				return false;
			cmt = (x+y+cmt)/n;
		}
		return true;
	}
	void Print(){
		for(int i = 0; i < n; i++)
			cout << num[i] << " ";
		cout << endl;
	}
	void dfs(int k){
		if(Prune()) return;
		if(n==k){
			if(Judge()){
				Print();
				exit(0);
			}
		}
		//Print();
		for (int i=n-1; i>=0; i--){
			if(!vis[i]){
				vis[i]=1;
				//num[k]=i;
				num[next[k]]=i;
				//Print();
				dfs(k+1);
				vis[i]=0;
				//num[k]=-1;
				num[next[k]]=-1;
			}
		}
	}
};
int main(){
	Velco test;
	test.dfs(0); 
	return 0;
} 
