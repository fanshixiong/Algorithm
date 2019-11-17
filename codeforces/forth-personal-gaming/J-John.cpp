#include<bits/stdc++.h> 
using namespace std;
const int maxn = 1e3;
int num[maxn]; 
int n;


int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		int res = 0, Ans=1;
		bool tag = 0;           //若都为1，按照奇偶性判断 
		for(int i=1; i<=n; i++){
			cin >> num[i];
			res ^= num[i];
			if(num[i] != 1)
				tag = 1;
		}
		if(!tag){
			if(n&1)
				cout << "Brother" <<endl;
			else
				cout << "John" << endl;
		}
		
		else{
		
			if(res)
				cout << "John" << endl;
			else
				cout << "Brother" <<endl;
		}	
	}
	return 0;
}
