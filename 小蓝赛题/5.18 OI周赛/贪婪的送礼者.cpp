#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
map<string, int> mmp;
int main(){
	int n; cin >> n;
	vector<string> name(n+1);
	for(int i=0; i<n; i++){
		cin >> name[i];
	}
	for(int i=0; i<n; i++){ 
		string s;	
		int x, y;
		cin >> s >> x >> y;
		int tmp=0;
		if(y!=0){
			tmp=x/y;
		}
		mmp[s]-=tmp*y; //
		for(int j=0; j<y; j++){
			string str;
			cin >> str;
			mmp[str] += tmp;
		}
	}
	for(int i=0; i<n; i++){
		cout << name[i] << " " << mmp[name[i]] <<endl;
	}
	return 0;
}
