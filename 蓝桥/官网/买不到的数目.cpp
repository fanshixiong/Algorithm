#include <iostream>
#include <vector>
using namespace std;
vector<int> num(1000005);
int x4=0, x7=0;
int min(int x, int y){
	if(x < y){
		x4++;
		return x;
	}
	else if (x > y){
		x7++;
		return y;
	}
	else{
		x4++; x7++;
		return x;
	}
}
int main(){
	int n, m;
	cin >> n >> m;
	num[0]=0;
	for (int i = 1; i <= n*m; i++){
		num[i]=min(num[x4]+n, num[x7]+m);
	//	cout << num[i] << " ";
	}
//	cout << endl;
	for (int i = n*m; i>=1; i--){
		if(num[i]-1 != num[i-1]){
			cout << num[i]-1 << endl;
			return 0;
		}
	}
	return 0;
}
