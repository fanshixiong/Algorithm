#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n=s.size();
		set<char> st;
		int i=0, j=0;
		while(i<n){
			int cnt=0;
			while(s[i] == s[j]){
				cnt++;
				j++;
			}
			if(cnt % 2){
				//cout<< s[i] << " ";
				st.insert(s[i]);
			}
			i=j;
		} 
		int m=st.size();
		for(int i=0; i<m; i++){
			cout<<*st.begin();
			st.erase(*st.begin());
		}
  	  	cout << endl;
	}
	return 0;
}
