#include<bits/stdc++.h>

using namespace std;

#define ll unsigned long long

int main(){
	string s;
	cin >> s;
	string ans = "";
	vector<int> num;
	int sum = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			sum = sum*10+(s[i]-'0');
		}
		else {
			if(sum != 0){
				char c = ans[ans.size()-1];
				for(int j=0; j<sum-1; j++) ans += c;
			}
			ans += s[i];
			sum = 0;
		}
	}
	if(sum != 0){
		char c = ans[ans.size()-1];
		for(int j=0; j<sum-1; j++) ans += c;
	}
	
	cout << ans << endl;
	return 0;
} 
