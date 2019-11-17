#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int FlowShop (int n, vecotr<int> a, vector<int> b, vector<int> c){
	class Jobtype{
		public:
			int operator <= (Jobtype a) const{
				return key<=a.key;
			}
			int key, index;
			bool job;
	};
	vector<Jobtype> d(n);
	for (int i = 0; i < n; i++){
		d[i].key = a[i] > b[i] ? b[i] : a[i];
		d[i].job = a[i] <= b[i];
		d[i].index = i;
	}
	sort(d);
	int j = 0, k = n-1;
	for (int i = 0; i < n; i++){
		if (d[i].job) c[j++] = d[i].index;
		else c[k--] = d[i].index;
	}
	j = a[c[0]];
	k = j + b[c[0]];
	for (int i 1; i < n; i++){
		j += a[c[i]];
		k = j < k ? k + b[c[i]] : j + b[c[i]];
	}
	return k;
}

int main(){
	return 0;
} 
