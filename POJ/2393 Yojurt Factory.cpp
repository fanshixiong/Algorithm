#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>
using namespace std;
int main(){
	long long n, s;
	cin >> n >> s;
	long long ans=0, tp=0x3f3f3f3f;
	for(long long i=0; i<n; i++){
		long long c, y;
		cin >> c >> y;
		tp = min(tp+s, c);
		ans += tp*y;
	}
	cout << ans << endl;
	return 0;
}
