#include <iostream>
 #include <cmath>
 #include <vector>
 #include <algorithm>
 #include <queue>
 using namespace std;
 int main(){
 	int n; cin >> n;
	string s; cin >> s;
	long long num2=0, ans=0;
	for(int i=0; i<n; i++){
		if(s[i]-'0' == 2)
			num2++;
		if(s[i]-'0'==3)
			ans+=num2;
	} 
	cout << ans << endl;
 	return 0;
 } 
