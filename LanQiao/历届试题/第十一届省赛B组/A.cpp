#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int S = 10000;
	int sun = 10, ad = 5;
	
	int t = 0, c = 0;
	bool flag = false;
	while(S > 0){
		if(!flag){
			S -= 10;
			t++;
			c++;
			if(c == 60){
				flag = !flag;
				c = 0;
			}
		}
		else{
			S += 5;
			t++;
			c++;
			if(c == 60) {
				flag = !flag;
				c = 0;
			}
		}
	}
	cout << t << endl;
	

	return 0;
}
