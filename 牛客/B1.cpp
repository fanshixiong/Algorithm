#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(const string a, const string b){
	return a.size() == b.size() ? (a < b) : (a.size() < b.size());
}
int main(){
	string s; cin >> s;
	string num;
	bool flag = false;
	vector<string> nums;
	for(int i = 0; i < (int)s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			flag = true;
			num += s[i];
		}
		else{
			if(flag){
				flag = false;
				nums.push_back(num);
				num = "";
			}
		}
	}
	if(flag){
		// cout << num << endl;
		nums.push_back(num);
	}
	vector<string> ans;
	for(auto c : nums){
		if(c.size() == 1){
			ans.push_back(c);
			continue;
		}
		bool f = 0;
		for(int i = 0; i < (int)c.size(); i++){
			if(c[i] != '0') {
				f = 1;
				break;
			}
		}
		if(!f){
			ans.push_back("0");
			continue;
		}
		string str = "";
		bool flag = false;
		for(int i = 0; i < (int)c.size(); i++){
			if(!flag && c[i] == '0') continue;
			flag = true; str += c[i];
		}	
		ans.push_back(str);
	}
	sort(ans.begin(), ans.end(), cmp);
	for(auto c : ans){
		cout << c << endl;
	}
	return 0;
}
/*
0He15l154lo87wor7l087d2d0d9
*/