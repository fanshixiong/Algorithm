#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main(){
	string str;
	cin >> str;
	if (str.find('A') == -1 && str.find('B') == -1){
		cout <<  "Superman Win" << endl;
		return 0;
	} 
	vector<string> man(3);
	man[0] = "Batman Win";
	man[1] = "Superman Win";
	man[2] = "Aquaman Win";
	int res = 0;
	map<char, int> num;
	num['A'] = 0;
	num['B'] = 1;
	num['C'] = 2;
	for (int i = str.size()-1; i>=0; i--){
		if ((num[str[i]]+res)%3 == 2)
			continue;
		else if((num[str[i]]+res)%3 == 1){
			res += 1;
		}
		else{
			res += 2;
		}
	}
	cout << res << endl;
	cout << man[res%3] << endl;
	return 0;
}
