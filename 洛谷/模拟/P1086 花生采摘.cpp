#include <iostream>
#include <cmath>
#include <vector> 
#include <algorithm>
using namespace std;
struct Peanut{
	int x, y, value;
};
bool cmp(Peanut &a, Peanut &b){
	return a.value > b.value;
}
int main(){
	int n, m, t;
	cin >> m >> n >> t; 
	int x;
	vector<Peanut> peanut;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			cin >> x;
			if(x){
				Peanut P;
				P.x = i; P.y = j;
				P.value = x;
				peanut.push_back(P); 
			}
		}
	}
	sort(peanut.begin(), peanut.end(), cmp);
	long res = 0;
	bool b = 0;
	if(2*peanut[0].x <= t-1){
		t -= peanut[0].x;
		res += peanut[0].value;
		t--;
		b = 1;
	}
	if(b){
		for (int i = 1; i < peanut.size(); i++){
			int tmp = abs(peanut[i-1].x- peanut[i].x) + abs(peanut[i-1].y-peanut[i].y);
			if((t-1-tmp-peanut[i].x) >= 0){
			//	cout << peanut[i].x <<" "<< peanut[i].y <<" "<< peanut[i].value << endl;
				t -= tmp;
				res += peanut[i].value;
				t--;
			}
			else
				break;
		}
	}
	cout << res << endl;
	return 0;
} 
