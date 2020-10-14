#include<bits/stdc++.h>

using namespace std;

const int maxn = 5e5+10;

double a[maxn];


int main(){
	int n, S;
	cin >> n >> S;
	
	double avg = 1.0 * S / n;
	
	for(int i = 0; i < n; i++) cin >> a[i];
	
	sort(a, a + n);
	
	double ans = 0.0, navg = avg;
	for(int p = 0; p < n; p++){
		if(a[p] < navg){
			ans += (double)pow(avg-a[p], 2);
			S -= a[p];
			navg = 1.0 * S / (n-p-1);
		}
		else{
			ans += (double)pow(navg-avg, 2);
		}
	}
	
	printf("%.4lf", sqrt(ans/n));
	return 0;
}
