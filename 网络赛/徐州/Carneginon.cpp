#include<bits/stdc++.h>
using namespace std;

string s1;
int q;
int main(){
	ios::sync_with_stdio(false);
	cin >> s1 >> q;
	int len1=s1.length();
	while(q--){
		string s2;
		cin >> s2;
		int len2 = s2.length();
		if(len1 == len2){
			if(s1==s2)
				cout << "jntm!" <<endl;
			else
				cout << "friend!" << endl;
		}
		else if(len1 > len2){
			string tmp1 = s1.substr(0, len2);
			if(tmp1 == s2)
				cout << "my child!" << endl;
			else
				cout << "oh, child!" << endl;
		}
		else{
			string tmp2 = s2.substr(0, len1);
			if(tmp2 == s1)
				cout << "my teacher!" <<endl;
			else
				cout << "senior!" << endl;
		}
	}
	return 0;
}

