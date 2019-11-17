  #include <iostream>
 #include <cmath>
 #include <vector>
 #include <algorithm>
 #include <queue>
 using namespace std;
 int main(){
 	int n; cin >> n;
 	long long ans=0;
 	vector<int> num(n);
 	for(int i=0; i<n; i++)
 		cin >> num[i];
 	sort(num.begin(), num.end());
 	long long tmp=0;
 	for(int i=0; i<n; i++){
 		tmp+=num[i];
 		ans+=tmp;
	}
	cout << ans << endl;
 	return 0;
 } 
