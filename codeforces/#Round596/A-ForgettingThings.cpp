#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int da, db;
	cin >> da >>db;
	int a, b;
	if(db-da==1){
		cout << da*10+9 << " " << db*10 << endl;
	}
	else if(da-db==0){
		cout << da*10+1 << " " << db*10+2 << endl;
	}
	else if(da-db==8){
		cout << da << " " <<db*10 << endl;
	}
	else{
		cout << -1 << endl;
	}
	return 0;
}
