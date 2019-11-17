#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
vector<int> num1(10005);
vector<int> num2(10005);
vector<vector<int> > table(101);
bool dfs(int k){
	for(int i = table[k].size()-1; i>=0; i--){
		int q = table[k][i];
		if(num1[q]){
			num1[q]--;
			bool b = dfs(q);
			num1[q]++;
			if(b)
				return 0;
		}
	}
	return 1;                     //没有可选了，输 
}
int main(){
	int x, y;
	int n = 0, m = 0;
	while (cin >> x){
		num1[x]++;n++;
		if(getchar() == '\n')
			break;
	
	}
	while(cin >> x){
		num2[m++]=x;
		if(getchar() == '\n')
			break;
	
	}
	for (int i = num1[0]; i < 101; i++){
		if(num1[i]){
			for (int j = 1; j < 101; j++){
				if (num1[j] && ((i%j==0) || (j%i== 0))){
					table[i].push_back(j);
				}
			}
		}
	}/*
	for (int i = 0; i < 101; i++){
		if(num1[i]){
			cout << i << "   ";
			for (int j = 0; j < table[i].size(); j++)
				cout << table[i][j] << " ";
		
			cout << endl;
		}
	}*/
	bool b;
	for(int i = 0; i < m; i++){
		num1[num2[i]]--;
		b=dfs(num2[i]); 
		num1[num2[i]]++;
		if(b){
			cout << num2[i] << endl;
			return 0;
		} 
	}
	cout << -1 << endl;
	return 0;
}
/*
int main(){
	int x, y;
	int n = 0, m = 0;
	while (cin >> x){
		num1[n++]=x;
		if(getchar() == '\n')
			break;
	
	}
	while(cin >> x){
		num2[m++]=x;
		if(getchar() == '\n')
			break;
	
	}
	//for (int i = 0; i < m; i++)
	//	cout << num2[i] << " ";
	vector<int> n2(m);
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			if(num1[j]%num2[i]==0 || num2[i]%num1[j]==0)
				n2[i]++;
		}
		n2[i]--;
	}
	int res = 0;
	bool b = 0;
	for (int i = 0; i<m; i++){
		if(n2[i]%2){
			if(n2[i] > n2[res])
				res = i;
			else if(n2[i]==n2[res]);
			b=1;
		}
		//cout << n2[i] << " ";
	}
	if(b)
		cout << num2[res] << endl;
	else
		cout << -1 << endl;
	return 0;
}
*/
