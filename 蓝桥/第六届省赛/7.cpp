#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
vector<string> v;
long long res = 0;
int main(){
	string str = "aaabbbbccccc";
	do{
		vector<string>::iterator it;
		for (it = v.begin(); it != v.end(); it++){
			if ((*it).find(str, 0) != string::npos)
				break;
		}
		if (it != v.end())
			continue;
		string s = str+str;
		v.push_back(s);
		reverse(s.begin(), s.end());
		v.push_back(s);
		res++; 
	}while(next_permutation(str.begin(), str.end()));
	cout <<res << endl;
	return 0;
}
