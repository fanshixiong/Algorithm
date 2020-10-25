#include<bits/stdc++.h>
using namespace std;

void quickSort(vector<int> &num, int l, int r){
	if(l >= r) return;
	
	int i = l, j = r, x = num[l];
	while(i < j){
		
		while(i < j && num[j] >= x) j--;
		if(i < j) num[i++] = num[j];
		while(i < j && num[i] <= x) i++;
		if(i < j) num[j--] = num[i];
	}
	num[i] = x;
	quickSort(num, l, i-1);
	quickSort(num, i+1, r);
}



int main(){
	vector<int> ans;
	ans.push_back(20);
	cout << ans.back() << endl;
	return 0;
} 
