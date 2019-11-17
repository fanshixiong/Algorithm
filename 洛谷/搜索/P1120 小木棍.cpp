#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> vis(100);
int m, n=0, max_x=0, min_x=0x3f3f, sum=0;
/**
@@arg: 	
		wat: wait to use, The remaining amount need patchwork,
		aul: already used max length, 
		tar: if this target length legal, 
		can: can use max length;
*/
void dfs(int wat, int aul, int tar, int can){ 
	if(wat==0){                       //This length legal
		cout << tar <<endl;
		exit(0);
	}
	if(aul == tar){
		dfs(wat-1, 0, tar, max_x);   //sum of used stick is target, legal, Enumbrate next 
		                             // dfs(wat-1, 0, tar, can) error: perement "can" changed and isn't max_x;
		return;
	}
	for(int i=can; i>=min_x; i--){
		if(vis[i] && i+aul <= tar){
			vis[i]--;
			dfs(wat, aul+i, tar, i); //because i already used and next length only need to i not max_x
			vis[i]++;
			if(aul==0 || aul+i==tar){ //target length too short to have little scheme to choose
				break;
			}
		}
	}
}
int main(){
	cin >> m;
	for(int i=0; i<m; i++){
		int x;
		cin >> x;
		if(x<=50){
			n++;
			sum+=x;
			min_x=min(min_x, x);
			max_x=max(max_x, x);
			vis[x]++;
		}
	}
	int tmp=sum/2;
	for(int i=max_x; i<=tmp; i++){
		if(sum%i==0){
			dfs(sum/i, 0, i, max_x);  //Enumerate each length 
		}                             // sum/i means the number of have to patchwork ,not the number of sticks
	}
	cout << sum << endl; // Half the sum of the lengths still no solution, and then for the original
	return 0;
}

