#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e6+10;
int k;
string s;
void solve(){
	if(s.size() % k != 0){
        cout << -1 << endl;
        return;
    }
    string str = s;
    int j = s.size() - 1;
    while(1){
    	if(str[j] == 'a') j--;
    	
    }
}
int main(){
	cin >> k >> s;
    solve();
	return 0;
}