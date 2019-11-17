#include<bits/stdc++.h>
using namespace std;

struct node{
	int id;
	string str;
	node(int i){
		id = i;
	}
};
bool cmp(node &a, node &b){
	return a.id < b.id;
}
int main(){
	vector<node> a;
	int x, n = 0;
	string ss;
	getline(cin, ss);
	stringstream s(ss);
	while(s >> x){
		a.push_back(node(x));
		n++;
	}
	//cout << n << endl;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		a[i].str = s;
	}
	sort(a.begin(), a.end(), cmp);
	for(int i=0; i<n; i++){
		cout << a[i].str << endl;
	}
	return 0;
}
