#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring> 
using namespace std;
int main(){
	string s;
	cin >> s;
	int tc1=0,ta1=0, tt1=0;
	long long ans=0;
	vector<int> tc(s.size()+1);
	for(int i=0; i<s.size(); i++){
		if(s[i]=='C')
			tc1++;
		tc[i]=tc1;
	}
	for(int i=s.size()-1; i>=0; i--){
		if(s[i]=='T')
			tt1++;
		if(s[i]=='A')
			ans = (ans+tt1*tc[i])%1000000007;
	}
	cout << ans << endl;
	return 0;
} 
