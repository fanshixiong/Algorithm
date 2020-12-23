#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

#define pb push_back
const int maxn = 5e3+10;
vector<int> G[maxn];
int vis[maxn];
int tans, s;
#define ll long long
const int mod = 1e9+7;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param arr int整型vector 
     * @param a int整型 
     * @param b int整型 
     * @return int整型
     */
    int countTriplets(vector<int>& arr, int a, int b) {
        // write code here
        ll ans = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(arr[j] - arr[i] > a) continue;
                for(int k = j+1; k < n; k++) if(arr[k] - arr[j] <= b) ans++;
            }
        }
        cout << "1: "<< ans << endl;
        ans = 0;
        sort(arr.begin(), arr.end());
        //for(auto c : arr) cout << c << " ";
         //   cout << endl;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(arr[j] - arr[i] > a) continue;
                int k = lower_bound(arr.begin()+j+1, arr.end(), arr[j]+b+1)-arr.begin();
                cout << i << " " << j << " " << k <<endl;
                ans = (ans + k-1-j) % mod;
            }
        }
        cout << ans << endl;
        
        return ans;
    }
};
int main(){
    int n; cin >> n;
    vector<int> l(n);
    for(int i = 0; i < n; i++) cin >> l[i];
    int a, b; cin >> a >> b;

    Solution *s = new Solution();
    s->countTriplets(l, a, b);
    return 0;
}
/*
30
12 8 11 4 1 8 3 3 2 1 5 3 5 6 7 3 2 1 3 12 13 14 15 16 12 13 14 16 17 0 0
3 4
*/