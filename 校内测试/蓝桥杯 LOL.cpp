#include <iostream>
#include <cstring>
using namespace std;
int dfs(string s){
	if (s.find("LOL") != -1)
		return -1;
	if (s.find('*') == -1)
		return 0;
	int res = -1;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '*'){
			s[i] = 'L';
			res = max(res, -dfs(s));
			if (res == 1) {
				s[i] = '*';
				return 1;
			}
			s[i] = 'O';
			res = max(res, -dfs(s));
			if (res == 1) {
				s[i] = '*';
				return 1;
			}
			s[i] = '*';
		}
	}
	return res;
}
int main(){
	int N;
	cin >> N;
	while (N--){
		string s;
		cin >> s;
		cout << dfs(s) << endl;
	}	
	return 0;
}

