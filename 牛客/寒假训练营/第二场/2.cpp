#include<bits/stdc++.h>
using namespace std;

/*
int getCount(string s){
	int cnt = 0;
	int i = s.size() - 1;

	while(i >= 0 && s[i] == ' ') i--;

	for(; i >= 0; i--){
		if(s[i] == ' ') break;
		cnt ++;
	}
	return cnt;
}

*/

bool isAlpha(char c){
	return c >= 'a' && c <= 'z';
}

int getCount(string s){
	int maxCnt = 0;
	int i = 0;
	while(i < (int)s.size() && s[i] == ' '){
		i++;
	}
	while(i < (int)s.size()){
		if(isAlpha(s[i])){
			int beg = i;
			while(i < (int)s.size() && isAlpha(s[i])) i++;
			if(i == (int)s.size() || s[i] == ' '){
				maxCnt = max(maxCnt, i - beg);
			}
			else{
				while(i < (int)s.size() && s[i] != ' ') i++;
				i++;
			}
		}
		else{
			while(i < (int)s.size() && s[i] != ' ') i++;
			i++;
		}
	}

	return maxCnt;
}

int main(){ 
	string s = "  123 1wor3ld it's it iss   ";
	cout << getCount(s);
	return 0;
}