#include<bits/stdc++.h>
using namespace std;
int cnt_0, cnt_1;
int n;
int len[55];
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		string s;
		int cnt=0;
		bool flg =0;
		int n;
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> s;
			if(s.size()%2)
				flg=1;
			int left=0, right=s.size()-1;
			while(left<right){
				if(s[left] != s[right])
					cnt++;
				left++;
				right--;
			}
		}
		if(cnt % 2==0)
			cout << n << endl;
		else if(cnt%2 && flg)
			cout << n << endl;
		else
			cout << n-1 << endl;
	}
	return 0;
}
