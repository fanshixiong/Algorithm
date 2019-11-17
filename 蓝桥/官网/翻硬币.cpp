#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;
int main(){
	string tar, beg;
	cin >> beg >> tar;
	vector<int> same(beg.size());
	for(int i=0; i<beg.size(); i++){
		if(tar[i]==beg[i])
			same[i]=0;
		else
			same[i]=1;
	}
	bool sign=0;
	int gap, ans=0;
	for(int i=0; i<beg.size(); i++){
		if(same[i]==1){
			if(sign){
				ans+=(i-gap);
				sign=0;
			}
			else
				gap=i, sign=1;
		}
	}
	cout << ans << endl;
	return 0;
} 
