#include<iostream>
#include<cmath>
using namespace std;
bool vis[10];
int num[10];
bool judge(){
	long long ans=0;
	for(int i=0; i<10; i++)
		ans=ans*10+num[i];
	long long x=sqrt(ans);
	if(x*x == ans)
		return true;
	return false;
}
void print(){
	for(int i=0; i<10; i++)
		cout << num[i];
	cout << endl;
}
void dfs(int k){
	if(k>10) return;
	if(k==10){
		if(judge()){
			print();
		}
		return;
	}
	for(int i=9; i>=0; i--){
		if(!vis[i]){
			vis[i]=1;
			num[k]=i;
			dfs(k+1);
			num[k]=0;
			vis[i]=0;
		}
	}
}
int main(){
	dfs(0); 
	return 0;
} 
