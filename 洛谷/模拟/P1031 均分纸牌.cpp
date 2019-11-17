#include <iostream>
#include <vector>
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<int> puko(N+1);
	int sum = 0;
	for (int i = 1; i <= N; i++){
		cin >> puko[i];
		sum += puko[i];
	}
	int pj = sum / N;
	int res = 0;
	for (int i = 1; i < N; i++){
		puko[i] -= pj;
		if(puko[i]){
			res++;
			puko[i+1] += puko[i]; 
		}
	//	cout << puko[i] << " ";
	}
	cout << res <<endl;
	return 0;
} 
