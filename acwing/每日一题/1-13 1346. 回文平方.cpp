#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;

//二十进制以内扩展到K即可，若要求大于二十进制可以以此类推
char B[25] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};

//函数将十进制数x转化为y进制数并以字符串形式输出
string trans(int x, int y) {
    string str = "";
    while (x) {
        str += B[x % y];
        x /= y;
    }
    //因为string是一种类似栈的结果，所以要翻转后才能保持正序
    reverse(str.begin(),str.end());
    return str;
}

//判断x所转化的y进制数是否为回文串
bool check(int x, int y) {
    string s = trans(x, y);
    bool flag = true;
    int m = s.size();
    for (int i = 0; i < m; i++) 
        if (s[i] != s[m - i - 1])
            flag = false;
    return flag;
}

void solve(){
    int n; cin >> n;
    for (int i = 1; i <= 300; i++) {
        if (check(i * i, n)) {
            string s1 = trans(i, n);
            string s2 = trans(i * i, n);
            cout << s1 << ' ' << s2 << endl;
        }
    }
}
int main(){
    IOS; int t = 1;
    while(t--){
        solve();
    }
    return 0;
}