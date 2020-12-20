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
     * @param a int整型vector 
     * @return int整型
     */
    int n;
    bool judge(vector<int> &a, int x){
        unordered_map<int, int> p;
        for(int i = n, c = 0; c < x; c++, i--) p[i] = 1; 
        
        cout << x << " " << p.size() << endl;
        vector<int> b;
        for(int i = 0; i < n; i++){
            if(!p.count(a[i])) b.push_back(a[i]);
        }
        for(int i = 1; i < (int)b.size(); i++){
            if(b[i] <= b[i-1]) return false;
        }
        return true;
    }
    int wwork(int n, vector<int>& a) {
        // write code here
        this->n = n;
        int ans = 0, l = 0, r = n-1;
        while(l <= r){
            int mid = (l+r)/2;
            if(judge(a, mid)){
                cout << mid << endl;
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};
int main(){
    int n; cin >> n;
    vector<int> a(n); 
    for(int i = 0; i < n; i++) cin >> a[i];

    Solution *s = new Solution();
    cout << s->wwork(n, a) << endl;
}
/*
5
2 1 4 5 3
*/