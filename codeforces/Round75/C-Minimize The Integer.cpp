#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		queue<int> odds, evens;
		for(int i=0; i<s.size(); i++){
			if((s[i]-'0')%2)
				odds.push(s[i]-'0');
			else	
				evens.push(s[i]-'0');
		}
		while((!odds.empty()) || (!evens.empty())){
			if(odds.empty()){
				cout << evens.front();
				evens.pop();
			}
			else if(evens.empty()){
				cout << odds.front();
				odds.pop();
			}
			else{
				if(odds.front() < evens.front()){
					cout << odds.front();
					odds.pop();
				}
				else{
					cout << evens.front();
					evens.pop();
				}
			}
		}
		cout << endl;
	}
	return 0;
}
