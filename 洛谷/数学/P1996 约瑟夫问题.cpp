#include<iostream>
#include<vector>
using namespace std; 
int main(){
	int n,m;
	cin >> n>> m;	
	vector<int> num(n);
	// vector<int> num(n+1) error@
	if(n==0)
		return 0;
	for(int i=0; i<n; i++)	
		num[i]=i+1;
	int tmp=0;
	while(num.size() > 1){
		tmp=(tmp+m-1)%num.size();
		cout << num[tmp] << " ";
		num.erase(num.begin()+tmp);
	}
	cout << num[0] << endl;
	return 0;
} 

