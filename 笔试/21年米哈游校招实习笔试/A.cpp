#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+10;
ll f[maxn][4];
bool judge(char c){
	if(c == '1' || c == '8' || c == '0' || c == '7') return false;
	return true;
}
int main(){
	string s; cin >> s;
	memset(f, 0, sizeof f);

	for(int i = 1; i <= (int)s.size(); i++){
		if(s[i-1] == '1'){
			f[i][0] = f[i-1][0] + 1;
		}
		if(s[i-1] == '8'){
			if(f[i-1][0] != 0) f[i][1] = max(f[i-1][1], f[i-1][0]) + 1;
		}
		if(s[i-1] == '0'){
			if(f[i-1][1] != 0) f[i][2] = max(f[i-1][2], f[i-1][1]) + 1;
		}
		if(s[i-1] == '7'){
            if(f[i-1][2] != 0) f[i][3] = max(f[i-1][3], f[i-1][2]) + 1;
		}
		// if(judge(s[i-1])) continue;
		f[i][0] = max(f[i][0], f[i-1][0]);
		f[i][1] = max(f[i][1], f[i-1][1]);
		f[i][2] = max(f[i][2], f[i-1][2]);
		f[i][3] = max(f[i][3], f[i-1][3]);
	}
    int ans = f[(int)s.size()][3];
	cout << ans << endl;
	return 0;
}