#include <iostream>
#include <vector> 
using namespace std; 
int main(){
	int n;
	cin >> n; 
	vector<int> x0(n+1), y0(n+1), x1(n+1), y1(n+1);
	for (int i = 1; i <= n; i++){
		cin >> x0[i] >> y0[i] >> x1[i] >> y1[i];
		x1[i] += x0[i];
		y1[i] += y0[i];
	}
	int x, y;
	cin >> x >> y;
	for (int i = n; i > 0; i--){
		if (x0[i] <= x && x1[i] >= x && y0[i] <= y && y1[i] >= y){
			cout << i <<endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
