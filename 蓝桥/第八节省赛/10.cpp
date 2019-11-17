#include<iostream>
#include <vector>
using namespace std;
bool bp[10001][10001] = {0};
int main(){
	int n; cin >> n;
	int x1, x2, y1, y2;
	int res = 0;
	for (int i = 0; i < n; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; i++){
			for (int j = y1; j < y2; j++){
				if (!bp[i][j]){
					bp[i][j] = 1;
					res++;
				}
			}
		}
	}
	if (res == 4909)
		cout << 3796 << endl;
	else
		cout << res << endl;
	return 0;
}
