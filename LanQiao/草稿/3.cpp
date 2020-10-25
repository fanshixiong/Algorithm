#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>

using namespace std;

int josephus(int n, int m){
	int f = 0;
	for(int i = 2; i != n+1; i++){
		f = (f+m)%i;
	}
	return f;
}
int josrphus2(int n, int m){
	if(n == 1) return 0;
	return (josrphus2(n-1, m)+m)%n;
}

int eurler_phi(int n){
	int res = n;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			res = res / i * (i-1);
			while(n % i == 0) n /= i;
		}
	}
	if(n != 1) res = res / n * (n - 1);
	return res;
}
int main(){
	
	return 0;
} 
