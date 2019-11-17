#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int res = 0;
	vector<int> num(n);
	for (int i= 0; i <n; i++)
		cin >> num[i];
	for (int left = 0; left < n; left++){
		int maxx = num[left], minx = num[left];
		for (int right = left; right < n; right++){
			minx = min(minx, num[right]);
			maxx = max(maxx, num[right]);
			if (maxx-minx == right-left)
				res++;
		}
	}
	cout << res << endl;
	return 0;
} 
