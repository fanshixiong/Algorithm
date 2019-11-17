#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int n=s.size();
	string x, y;
	bool b=0;
	for(int i=0; i<n; i++){
		if(s[i]=='Z')
			b=1;
		else if(b==1){
			cout << -1 << endl;
			return 0;
		} 
	} 
	for(int i=0; i<n; i++){
		if(s[i]=='X'){
			x += "2";
			y += "1";
		}
		else if(s[i]=='Y'){
			x += "1";
			y += "2";
		}
		else{
			x += "0";
			y += "0";
		}
	}
	cout << x << endl << y << endl;
	return 0;
}
