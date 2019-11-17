#include <iostream>
using namespace std;
int main(){
	int N;
	cin >> N;
	int res = N;
	int yus , chus;
	chus = N;
	while (chus > 0){
		yus += chus%3;
		chus = chus/3;
		res += chus;
	}
	cout << res+yus/3 <<endl;
	return 0;
}
