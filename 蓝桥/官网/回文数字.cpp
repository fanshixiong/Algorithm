#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N;
vector<int> num(6);
int numb(){
	int ans=0;
	for (int i=0; i<6; i++)
		ans+=num[i];
	return ans;
}
void dfs1(int k){
	if (numb()>N) return;
	if (k==3){
		if(numb()==N && num[0]!=0){
			for (int i=0; i<5; i++)
				cout << num[i];
			cout << endl;
		}
		return;
	}
	for (int i=0; i<=9; i++){
		num[k]=i;num[4-k]=i;
		dfs1(k+1);
		num[k]=0;num[4-k]=0;
	}
}
void dfs2(int k){
	if (numb()>N) return;
	if (k==3){
		if(numb()==N && num[0]!=0){
			for (int i=0; i<6; i++)
				cout << num[i];
			cout << endl;
			num[2]=num[3]=0;
		}
		return;
	}
	for (int i=0; i<=9; i++){
		num[k]=i;num[5-k]=i;
		dfs2(k+1);
		num[k]=0;num[5-k]=0;
	}
}
int main(){
	cin >> N;
	if (N>54){
		cout << -1 << endl;
		return 0;
	}
	if (N==54){
		cout << 999999 << endl;
		return 0;
	}
	if (N>45)
		dfs2(0);
	else{
		dfs1(0);
		dfs2(0);
	}
	return 0;
}
