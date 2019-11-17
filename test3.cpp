/*Ð¡À¶Èü£º ¿¾¼¦ 
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> nums(n);
	vector<int> sum(n+1);
	if (m <= 0){
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	int k = 0;
	sum[0] = nums[0];
	for (int i = 1; i < n; i++){
		if ((sum[k] < 0 && nums[i] < 0 )|| (nums[i] > 0 && sum[k] > 0)){
			sum[k] += nums[i];
		}
		else{
			k++;
			sum[k] = nums[i];
		}
	}
	n = k+1;
	int top = 0, sums = 0;
	for (int i = 0; i <= k; i++){
		if (sum[i] > 0){
			top++;
			sums += sum[i];
		}
	}
	if (top <= m){
		cout << sums << endl;
		return 0;
	}
	if (sum[0] < 0){
		sum.erase(sum.begin()); 
		n--;
	}
	if (sum[n] < 0){
		sum.erase(sum.begin() + n);
		n--; 
	}
	map<int, int> mmp;
	vector<int> x(n);
	for (int i = 0; i < n; i++){ 
		mmp[abs(sum[i])] = i;
		x[i]=abs(sum[i]);
	}
	sort(x.begin(), x.end());
	m = top-m;
	for (int i = 0; i < m; i++){
		if (mmp[x[i]] && sum[mmp[x[i]]] > 0){
			sums -= x[i];
			mmp.erase(x[i]);
		}
		else{
			sums -= x[i];
			mmp.erase(sum[mmp[x[i]]+1]);
			mmp.erase(x[i]);
			mmp.erase(sum[mmp[x[i]]-1]);
		}
	}
	cout << sums << endl; 
	return 0;
}


