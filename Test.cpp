#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int maxn = 2e5 + 10;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param n int整型 
     * @param k int整型 
     * @param Point int整型vector 
     * @return int整型vector
     */
    vector<int> city(int n, int k, vector<int>& Point) {
        // write code here
        
    }
};
int main(){
    int n, m; cin >> n >> m;
    vector<int> l(n);
    for(int i = 0; i < m; i++) cin >> l[i];

    Solution *s = new Solution();
    cout << s->oddnumber(n, m, l) << endl;
}
/*
3 2
1 2 3
*/