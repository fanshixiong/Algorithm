#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回m天后高度为奇数的树的数量
     * @param n int整型 
     * @param m int整型 
     * @param l int整型vector 
     * @param r int整型vector 
     * @return int整型
     */
    int oddnumber(int n, int m, vector<int>& l, vector<int>& r) {
        // write code here
        vector<int> f(n+1, 0);
        for(int i = 0; i < m; i++){
            f[l[i]]++;
            f[r[i]+1]--;
        }
        
        for(int i = 1; i <= n; i++){
            f[i] += f[i-1];
        }
        
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if((f[i]+m) & 1) ans++;
        }
        for(int i = 0; i <= n; i++) cout << f[i] + m << " ";
        cout << endl;
        return ans;
    }
};
int main(){
    int n, m; cin >> n >> m;
    vector<int> l(m), r(m);
    for(int i = 0; i < m; i++) cin >> l[i];
    for(int i = 0; i < m; i++) cin >> r[i];

    Solution *s = new Solution();
    cout << s->oddnumber(n, m, l, r) << endl;
}
/*
3 2
1 2
2 3
*/