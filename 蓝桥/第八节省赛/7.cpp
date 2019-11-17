#include <iostream>
#include <vector>
using namespace std;
int dfs(){
	char c;
	int y = 0, x = 0;
	while (1){
		c = getchar();
		if (c == 'x'){
			x++;
		}
		else if (c == '(')
			x += dfs();
		else if (c == '|'){
			y = max(x, y);
			x = 0;
		}
		else {
			y = max(x, y);
			return y;
		}	
	}
}
int main(){
	cout << dfs() << endl;
	return 0;
}
